# BTree-Database
This project aims to implement a relational database that manages relationships between tables.

## Introduction
The BTree-Database is designed to simulate a simple relational database system. It allows users to create tables, insert, update, and delete records, and query data using SQL-like commands. This project is an educational exercise aimed at understanding the core concepts of databases and B-trees.

## Table Structure
Each table consists of the following components:
- **Field**: A single piece of information about a person or an object.
- **Record**: A combination of several fields that form a row in the table.
- **Title**: Each column has a unique title, and all the data stored in a column must be of the same type.

## Supported Queries
The following SQL-like queries are supported in this project:

- `CREATE TABLE {table_name} (column1 type, column2 type, ...)`
- `INSERT INTO {table_name} VALUES (field1, field2, ...)`
- `DELETE FROM {table_name} WHERE {condition}`
- `UPDATE {table_name} SET (field1, field2, ...) WHERE {condition}`
- `SELECT {column1, column2, ... | *} FROM {table_name} WHERE {condition}`


