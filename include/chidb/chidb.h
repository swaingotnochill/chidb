/* Header for ChiDB API for clients.*/

#ifndef CHIDB_H_
#define CHIDB_H_

typedef struct chidb chidb;
typedef struct chidb_stmt chidb_stmt;

/* API return codes */
#define CHIDB_OK (0)
#define CHIDB_EINVALIDSQL (1)
#define CHIDB_ENOMEM (2)
#define CHIDB_ECANTOPEN (3)
#define CHIDB_ECORRUPT (4)
#define CHIDB_ECONSTRAINT (5)
#define CHIDB_EMISMATCH (6)
#define CHIDB_EIO (7)
#define CHIDB_EMIUSE (8)

#define CHIDB_ROW (100)
#define CHIDB_DONE (101)


/* Opens a chidb file.
*
* Parameters:
* - file: the filename of the chidb file to open. If file does not exists,
*   create it.
* - db: opaque type representing a chidb database.
*
* Returns:
* - CHIDB_OK: Operation successful.
* - CHIDB_ENOMEM: Could not allocate memory.
* - CHIDB_ECANTOPEN: Unable to open database file.
* - CHIDB_ECORRUPT: The database file is not well formed.
* - CHIDB_EIO: I/O error has occured while accessing the file.
*
*/
int chidb_open(const char* file, chidb** db);

/* Close the chidb file.
*
*  Parameters:
*  - db: opaque type representing the database.
*
*  Returns:
*  - CHIDB_OK: Operation successful.
*  - CHIDB_EMIUSE: db is already closed.
*/
int chidb_close(chidb** db);

/* Prepares a SQL statement for execution.
*  
*  Parameters:
*  - db: opaque type representing the database.
*  - sql: sql statement itself.
*  - chidb_stmt: returns a pointer to chidb_stmt variable.
*   
*  Returns:
*  - CHIDB_OK: Operation successful.
*  - CHIDB_EINVALIDSQL: sql is not valid.
*  - CHIDB_ENOMEM: could not allocate memory.
*/
int chidb_prepare(chidb** db, const char* sql, chidb_stmt **stmt);


/*
* Runs a prepared SQL statement until a result row is available (or just
* runs the sql statement to completion like INSERT.)
*
* Parameters:
* - stmt: sql statement to run
*
* Returns:
* - CHIDB_ECONSTRAINT: sql statement failed due to a constraint violation.
* - CHIDB_EMISMATCH: data type mismatch.
* - CHIDB_ENOMEM: could not allocate memory.
*/
int chidb_step(chidb_stmt **stmt);


/*  Finalizes a sql statement.
*   
*   Paramters:
*   - stmt: sql statment to finalize.
*   
*   Returns:
*   - CHIDB_OK: Operation successful.
*   - CHIDB_MISUSE: statement is already finalized.
* 
*/
int chidb_finalize(chidb_stmt **stmt);



#endif // CHIDB_H_


