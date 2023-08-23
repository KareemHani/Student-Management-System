# Student-Management-System
A student management system that provides 4 operations: Add Student , Remove Student, Retrieve Student's data, Update Student's data
The System will store the following information about the student: 1) Student Name
                                                                   2) Student ID
                                                                   3) Student Gender
                                                                   4) Academic Year
                                                                   5) GPA

                                                                   
First Operation Description: Adding a student will take the previous mentioned 5 information Fields, The system will do some error checks 
for the student name, the system must check that the user entered only the first and the last name.
for the student id, the system must check that the user entered a unique 7 digit number so entering the same id of existing student is not acceptable
for the student gender , the user must enter 'M' (For Male) and 'F' (For Female).
for the academic year, an integer value between 1 and the maximum number of academic year is the only accepted case.
for the gpa, it must be a positive floating number between 0.0 and 4.0.



Second Operation Description: Removing a student will ask the user about the ID of the student that you wish to remove from the system.
only 3 outputs are possible: 1) Invalid ID , if the entered student id is not a unique 7 digit.
                             2) ID not found, if the entered student id doesn't exist in the system.
                             3) Operation Successful, when the system removes the student's data



Third Operation Description: Retrieving Student's data, the user will choose either one of two options 1) Search by name
                                                                                                       2) Search by ID
one of three possible outcomes: 1) Invalid Name/ID
                                2) Student not found
                                3) Operation Successful



Fourth Operation Description: Updating Student's data, the system will ask the user for the student id then check if this id is valid.
this operation makes the system provide the user to update one of two option 1) Update the Academic Year
                                                                             2) Update the GPA
then the system will ask the user to enter the new value to be updated.
