#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the employee details
struct Employee {
    char name[50];
    int age;
    float salary;
    int id;
};

int main() {
    // Open the file in binary read/write mode
    FILE *file = fopen("employees.dat", "rb+");

    // Check if the file was opened successfully
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Move the file pointer to the second record
    fseek(file, sizeof(struct Employee), SEEK_SET);

    // Write a new employee record to the file
    struct Employee emp1 = {"John Doe", 30, 50000.0, 1001};
    fwrite(&emp1, sizeof(struct Employee), 1, file);

    // Move the file pointer to the first record
    fseek(file, 0, SEEK_SET);

    // Read the first employee record from the file
    struct Employee emp2;
    fread(&emp2, sizeof(struct Employee), 1, file);

    // Print the employee details
    printf("Name: %s\n", emp2.name);
    printf("Age: %d\n", emp2.age);
    printf("Salary: %.2f\n", emp2.salary);
    printf("ID: %d\n", emp2.id);

    // Close the file
    fclose(file);

    return 0;
}
