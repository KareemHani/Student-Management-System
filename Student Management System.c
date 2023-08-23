/*Author: Kareem Hani 
        Version:1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FACULTY_MAX_ACADEMIC_YEAR 5
#define Students_Max_Number 100
#define MAX_NAME_LENGTH 50
// Defining a Struct that contains all the students information
struct Student
{
    char Name[MAX_NAME_LENGTH];
    int ID;
    char Gender;
    int Academic_Year;
    float GPA;
};

// Defining an array of structs that contains the Max Number of Students
struct Student X[Students_Max_Number]; 

int total_no_of_students=0;

//Functions Prototypes
int is_StudentID_Unique(int ID);
void displayStudent(struct Student X);
void AddStudent();
void RemoveStudent();
void Retrive_Student();
void UpdateStudent();

void main()
{
    int choice;
    do{
        printf("/********************************************/\n");
        printf("        Student Management System       \n");
        printf("/********************************************/\n");

        printf("Choose the desired operation: \n");
        printf("1) Add a New Student \n");
        printf("2) Remove a Student \n");
        printf("3) Retrieve Student's Data \n");
        printf("4) Update Student's Data \n");
        printf("5) to exit the program\n"); // This is added to feature to allow the user to exit the program
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                AddStudent();
                break;
            }

            case 2:
            {
                RemoveStudent();
                break;
            }
            case 3:
            {
                Retrive_Student();
                break;
            }
            
            case 4:
            {
                UpdateStudent();
                break;
            }
            
           case 5:
           {
            printf("Exiting the program\n");
            break;
           }

           default:
           printf("Invalid Choice\n");

        }
    }while(choice!=5);



}// end of main



// Check if the Student ID is unique
int is_StudentID_Unique(int ID) 
{
    for (int i = 0; i < total_no_of_students; i++) 
    {
        if (X[i].ID == ID)
        {
            printf("ID is not Unique\n");
            return 0;
        }
    }
    printf("ID is Unique\n");
    return 1;
}
// Function to add the student and check for the errors
void AddStudent() 
{
    if (total_no_of_students >= Students_Max_Number) //checking for a space to add the new student
     {
        printf("Maximum number of students reached.\n");
        return;
    }

    // Defining New Object of the struct to add the student
    struct Student newStudent;
    
    // Input and validation loop for student name
    do {
        printf("Enter student name (First Last): ");
        
        scanf(" %[^\n]s" ,newStudent.Name);
        // This line checks if the entered name is larger than the allowed name space and prints error in this case
        if (strlen(newStudent.Name) > MAX_NAME_LENGTH) 
        {
            printf("Error: Student name is too long.\n");
            continue;
        }
        
        char temp;
        if (scanf("%c", &temp) != 1 || temp != '\n') 
        {
            printf("Error: Invalid input format.\n");
            continue;
        }
        
        // "sscanf" function extracts the first and last name entered and put them in different arrays
        char firstName[MAX_NAME_LENGTH];
        char lastName[MAX_NAME_LENGTH];
        
        if (sscanf(newStudent.Name, "%s %s", firstName, lastName) != 2) 
        {
            printf("Error: Please enter both first and last names.\n");
            continue;
        }
        
        newStudent.Name[0] = firstName[0];
        newStudent.Name[1] = '\0';
        strcat(newStudent.Name, " ");
        strcat(newStudent.Name, lastName);
        
        // if the previous steps went right, the break exits the loop
        break;
    } while (1);

    // Input and validation loop for student ID
    do {
        printf("Enter student ID (7 digits): ");
        if (scanf("%d", &newStudent.ID) != 1) 
        {
            printf("Error: Invalid input. Please enter a number.\n");
            continue;
        }
        // checking if the ID is 7-digit
        if (newStudent.ID < 1000000 || newStudent.ID > 9999999)
        {
            printf("Error: Student ID must be a 7-digit number.\n");
            continue;
        }
        // checking if the ID is Unique
        if (!is_StudentID_Unique(newStudent.ID)) {
            printf("Error: Student ID is not unique.\n");
            continue;
        }
        break;
    } while (1);

    // Input and validation loop for student gender
    do {
        printf("Enter student gender (M/F): ");
        if (scanf(" %c", &newStudent.Gender) != 1) 
        {
            printf("Error: InvalID input. Please enter 'M' or 'F'.\n");
            continue;
        }
        // Checking if the gender is either Male or Female
        if (newStudent.Gender != 'M' && newStudent.Gender != 'F') 
        {
            printf("Error: InvalID gender. Please enter 'M' or 'F'.\n");
            continue;
        }
        break;
    } while (1);

    // Input and validation loop for academic year
    do {
        printf("Enter academic year (1 - %d): ", FACULTY_MAX_ACADEMIC_YEAR);
        if (scanf("%d", &newStudent.Academic_Year) != 1) 
        {
            printf("Error: Invalid input. Please enter a number.\n");
            continue;
        }
        if (newStudent.Academic_Year < 1 || newStudent.Academic_Year > FACULTY_MAX_ACADEMIC_YEAR) {
            printf("Error: Academic year must be between 1 and %d.\n", FACULTY_MAX_ACADEMIC_YEAR);
            continue;
        }
        break;
    } while (1);

    // Input and validation loop for GPA
    do {
        printf("Enter GPA (0.0 - 4.0): ");
        if (scanf("%f", &newStudent.GPA) != 1) 
        {
            printf("Error: Invalid input. Please enter a number.\n");
            continue;
        }
        if (newStudent.GPA < 0.0 || newStudent.GPA > 4.0) {
            printf("Error: GPA must be between 0.0 and 4.0.\n");
            continue;
        }
        break;
    } while (1);

    X[total_no_of_students] = newStudent;
    total_no_of_students++;
    
    printf("Student added successfully.\n");
} // end of AddStudent Function

// Function to remove student from the list
void RemoveStudent()
{
    int Removed_ID;
    printf("Please enter the ID you want to remove \n");
    scanf("%d",&Removed_ID);
    if(Removed_ID<1000000 || Removed_ID>9999999)
    {
        printf("Invalid ID\n");
        return; // This immediately exits the current function preventing any further excution of the program
    }

    int found_index=-1; // we will use this variable to detect the index of the ID we want to remove
    for(int i=0;i<total_no_of_students;i++)
    {
        if(X[i].ID==Removed_ID)
        {
            found_index=i;
            break;
        }
    }

    if(found_index==-1)
    {
        printf("The ID you want to remove doesn't Exist\n");
        return;
    }
    
    // After removing the student, we need to shift the index of the elements after the removed student
    for(int j=found_index;j<total_no_of_students-1;j++)
    {
        X[j]=X[j+1];
    }
    total_no_of_students--;
    printf("Operation done: Student is removed\n");
} // end of RemoveStudent Function

// This function is used to display the data of the student
void displayStudent(struct Student X)
{
    printf("Name: %s \n",X.Name);
    printf("ID: %d\n", X.ID);
    printf("Gender: %c\n", X.Gender);
    printf("Academic Year: %d\n", X.Academic_Year);
    printf("GPA: %.2f\n", X.GPA);

}

// This function is used to Search for the student either by name or id
void Retrive_Student()
{   
    int choice;
    printf("Choose an Option\n");
    printf("1)Search by Name\n");
    printf("2)Search by ID\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
        {
            char Search_Name[MAX_NAME_LENGTH];
            printf("Enter Student Name\n");
            scanf("%s",Search_Name);

            printf("Search Results: \n");

            int foundCount = 0; // This Variable will be used to calculate number of results found or check if there is no result found

            // For loop was used here as because more than one student can have the same name, so it prints their info
            for (int i = 0; i < total_no_of_students; i++) 
            {
                if (strcmp(X[i].Name, Search_Name) == 0) 
                {
                    displayStudent(X[i]);
                    foundCount++;
                }
            }

            if(foundCount==0)
            {
                printf("Operation Failed: There is no student with this name \n");
            }

        }

        case 2:
        {
            int Search_ID;
            printf("Please enter the student's ID\n");
            scanf("%d",&Search_ID);

            if(Search_ID<1000000 || Search_ID>9999999)
            {
                printf("Invalid ID\n");
                return; // This immediately exits the current function preventing any further excution of the program
            }

            int found_index=-1; // we will use this variable to detect the index of the ID we are searching for
            for(int i=0;i<total_no_of_students;i++)
            {
                if(X[i].ID==Search_ID)
                {
                    found_index=i;
                    break;
                }
            }

            if(found_index==-1)
            {
                printf("The ID you are searching for doesn't Exist\n");
                return;
            }
            else
            {
                displayStudent(X[found_index]);
            }
            break;
        }
        default:
        printf("Invalid Choice");
    }
}// end of Retrive_Student Function

// This function is used to update the student's data
void UpdateStudent()
{
    int ID;
    printf("Enter the ID of the Student you wish to update\n");
    scanf("%d",&ID);

    // This condition is to check if the ID is 7-digits
    if(ID<1000000 || ID>9999999)
    {
        printf("Error, ID Must be 7-Digit\n");
        return; // This immediately exits the current function preventing any further excution of the program
    }

    int foundindex=-1;
    // This loop checks if the ID exists among the Students ID's
    for(int i=0;i<total_no_of_students;i++)
    {
        if(X[i].ID==ID)
        {
            foundindex=i;
            break;
        }
    }

    if(foundindex==-1)
    {
        printf("This ID Doesn't Exist\n");
        return;
    }

    int Choice;
    printf("Choose which one do u want to update:\n");
    printf("1) Academic Year \n");
    printf("2) GPA \n");
    printf("Enter your choice: ");
    scanf("%d", &Choice);

    switch(Choice)
    {
        // Updating the Academic Year
        case 1:
        {
            int New_Academic_Year;
            printf("Enter the Academic year \n");
            scanf("%d",&New_Academic_Year);

            // Checking if the academic year is valid
            if(New_Academic_Year<1 || New_Academic_Year>FACULTY_MAX_ACADEMIC_YEAR)
            {
                printf("Invalid Academic year, please enter a year between 1 and %d ",FACULTY_MAX_ACADEMIC_YEAR);
                return;
            }

            // Updating the student academic year
            X[foundindex].Academic_Year=New_Academic_Year;
            printf("Academic year is Updated Successfully\n");
            break;
        }// end of case 1

        //Updating the GPA
        case 2:
        {
            float New_GPA;
            printf("Please enter the New GPA to be Updated\n");
            scanf("%f",&New_GPA);

            //Checking if the entered GPA is valid
            if(New_GPA<0.0 || New_GPA>4.0)
            {
                printf("Invalid GPA, Please enter GPA between 0.0-4.0 \n");
                return;
            }

            // Update GPA
            X[foundindex].GPA=New_GPA;
            printf("GPA is Updated Successfully \n");
            break;

        }// end of Case 2

        default:
        printf("Invalid Choice\n");
        
    }
} // End of update_Student Function
