#include <stdio.h>
#include <string.h>

typedef struct person{
    char name[500];
    char email[500];
    int age;
    float weight,height,bmi;
}fiction;

void greeting();

int main() {
    greeting();
    int num_people;
    printf("Enter the number of people you are interested in: ");
    scanf("%d", &num_people);

    fiction person[num_people];
    for (int i = 0; i < num_people; i++) {
        printf("Enter details for person %d:\n", i + 1);

        // Enter name
        printf("First name: ");
        scanf("%s", person[i].name);

        // Enter email
        int email_exists = 1;
        while (email_exists) {
            printf("Email: ");
            scanf(" %[^\n]", person[i].email);

            // Check if email ends with "@gmail.com"
            if (strstr(person[i].email, "@gmail.com") == NULL) {
                printf("Please enter an email ending with @gmail.com\n");
            } else {
                // Check if email already exists
                email_exists = 0;
                for (int j = 0; j < i; j++) {
                    if (strcmp(person[i].email, person[j].email) == 0) {
                        printf("This email already exists. Please enter a different email.\n");
                        email_exists = 1;
                        break;
                    }
                }
            }
        }

        // Enter age, weight, and height
        printf("Age: ");
        scanf("%d", &person[i].age);

        printf("Enter weight (in kilograms): ");
        scanf("%f", &person[i].weight);

        printf("Enter height (in meters): ");
        scanf("%f", &person[i].height);

        person[i].bmi = person[i].weight / (person[i].height * person[i].height);
        
        printf("----------------------------------------------------------\n");
    }
    
    printf("\nRESULTS:\n");
    printf("_____________________________________________________________\n");
    printf("NAME          EMAIL                    AGE    BMI         WEIGHT STATUS\n");
    printf("____________  ________________________  _____  __________ ______________\n");

    for (int i = 0; i < num_people; i++) {
        printf("%-13s %-25s %d     %-10.2f", person[i].name, person[i].email, person[i].age, person[i].bmi);

        // BMI Category
        if (person[i].bmi < 18.5) {
            printf(" Underweight\n");
        } else if (person[i].bmi < 25) {
            printf(" Healthy weight\n");
        } else if (person[i].bmi < 30) {
            printf(" Overweight\n");
        } else if (person[i].bmi < 35) {
            printf(" Obesity\n");
        } else {
            printf(" Extremely obese\n");
        }
    }

    printf("--------------------------------------------------------------\n");
    printf("THANK YOU FOR USING THIS BMI CALCULATOR!\n");

    return 0;
}

void greeting()
{
    printf("Hi there! Do you want to know your BMI?\n");
}