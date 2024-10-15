#include<iostream>
#include <math.h>
#include <string>
using namespace std;

class BTNode;
class BTree; 

class Node{
public:
    int data;
    Node* nextfield;
    BTNode* self;
};


class BTNode
{
	Node **keys;
	int t;	 
	BTNode **C;
	int n;	
	bool leaf;
public:
	BTNode(int , bool ); 

	Node* insertNonFull(int k , Node* f);

	void splitChild(int i, BTNode *y);

	void traverse();
friend class BTree;
};


class BTree
{
	BTNode *root;
	int t; 
public:
	BTree(int t1){
	   root = NULL;
	   t = t1;}

	void traverse(){
	   if (root != NULL) root->traverse(); }

	Node* insert(int k , Node* f);
};


BTNode::BTNode(int t1, bool leaf1)
{
	t = t1;
	leaf = leaf1;
	keys = new Node *[2*t-1];
	C = new BTNode *[2*t];
	n = 0;
}


Node* BTree::insert(int k , Node* f)
{
        Node* a;
	Node* b;
	if (root == NULL){
	   root = new BTNode(t,true);
	   root->keys[0]->data=k;
	   root->keys[0]->nextfield=f;
	   root->n = 1;
		
	   return root->keys[0];}
		
	else{
	   if (root->n == 2*t-1){
	      BTNode *s = new BTNode(t, false);
	      s->C[0] = root;
	      s->splitChild(0, root);
	      int i = 0;
	      if (s->keys[0]->data < k) i++;
	      
	      a=s->C[i]->insertNonFull(k,f);

	      root = s;	
	      return a;}
	   else{
	      b=root->insertNonFull(k,f);
	      return b;}
          }
}


Node* BTNode::insertNonFull(int k , Node* f)
{
	int i = n-1;
	Node* a;
	
	if (leaf == true){
	  while (i >= 0 && keys[i]->data > k){
		keys[i+1]->data = keys[i]->data;
		i--;}
	  keys[i+1]->data = k;
	  keys[i+1]->nextfield=f;
	  n = n+1;}
	  
	else{
	  while (i >= 0 && keys[i]->data > k) i--;

	  if (C[i+1]->n == 2*t-1){
	     splitChild(i+1, C[i+1]);
	     if (keys[i+1]->data < k) i++;}
	     
	  a=C[i+1]->insertNonFull(k,f);}
}


void BTNode::splitChild(int i, BTNode *y)
{
	BTNode *z = new BTNode(y->t, y->leaf);
	z->n = t - 1;

	for (int j = 0; j < t-1; j++) z->keys[j]->data = y->keys[j+t]->data;

	if (y->leaf == false){
	   for (int j = 0; j < t; j++) z->C[j] = y->C[j+t];}

	y->n = t - 1;

	for (int j = n; j >= i+1; j--) C[j+1] = C[j];

	C[i+1] = z;

	for (int j = n-1; j >= i; j--) keys[j+1]->data = keys[j]->data;

	keys[i]->data = y->keys[t-1]->data;

	n = n + 1;
}


void BTNode::traverse()
{
	int i;
	for (i = 0; i < n; i++){
	   if (leaf == false)
	       C[i]->traverse();
	       cout << " " << keys[i];}
	       
	if (leaf == false) C[i]->traverse();
}

int hash1(string s , string* C , int n)
{
    C[n]=s;
    n+=1;
    return n;    
}


int hash2(string s1)
{
    int n,j=2;
    n=s1.length();
    int sum=0;
    int b=pow(10,n-4);
    for(int i=2 ; i<n ; i++){
       if(s1[i]=='/') continue;
       else j+=1;
       int a=1;
       a=a*(b/pow(10,j-2));
       int d=0;
       if(s1[i]== '1') d=1*a;  
       else if(s1[i]=='2') d=2*a;
       else if(s1[i]=='3') d=3*a;
       else if(s1[i]=='4') d=4*a;
       else if(s1[i]=='5') d=5*a;
       else if(s1[i]=='6') d=6*a;
       else if(s1[i]=='7') d=7*a;
       else if(s1[i]=='8') d=8*a;
       else if(s1[i]=='9') d=9*a;
       else if(s1[i]=='0') d=0*a;
       sum+=d;}
  
    return sum;
}


int hash3(string s1)
{
    int n;
    n=s1.length();
    int sum=0;
    int b=pow(10,n-1);
    for(int i=0 ; i<n ; i++){
       int a=1;
       a=a*(b/pow(10,i));
       int d=0;
       if(s1[i]== '1') d=1*a;  
       else if(s1[i]=='2') d=2*a;
       else if(s1[i]=='3') d=3*a;
       else if(s1[i]=='4') d=4*a;
       else if(s1[i]=='5') d=5*a;
       else if(s1[i]=='6') d=6*a;
       else if(s1[i]=='7') d=7*a;
       else if(s1[i]=='8') d=8*a;
       else if(s1[i]=='9') d=9*a;
       else if(s1[i]=='0') d=0*a;
       sum+=d;}
  
    return sum;
}



int main()
{
   BTree ID(2);
   BTree Nam(3);
   BTree JO(3);
   BTree IN(3);
   int a,n=0;
   string* C;
   C=new string [1000];
   Node* k;
   Node* r;
   Node* p;
   Node* I;
   cin >> a;
   int insert=0;
   for(int i=0 ; i<a+1 ; i++){
       string s1;
       getline(cin,s1);
       int b,l,e;
       b=s1.length();
       if(s1[0]=='I' || s1[0]=='i'){
          insert+=1;
          for(int j=0 ; j<b ; j++){
             if(s1[j]=='('){
                string s2;
                j+=2;
                while(s1[j]!='"'){
                     s2+=s1[j];
                     j+=1;}
                 j+=2;
                 n=hash1(s2,C,n);
                 
                 string s3;
                 while(s1[j]!=','){
                      s3+=s1[j];
                      j+=1;}
                  j+=1;
                  l=hash2(s3);
                  
                  string s4;
                  while(s1[j]!=')'){
                      s4+=s1[j];
                      j+=1;}
                  e=hash3(s4);}
           }
           k=IN.insert(e,NULL);
           r=JO.insert(l,k);
           p=Nam.insert(n,r);
           I=ID.insert(insert,p);} 

       }
   return 0;
}
