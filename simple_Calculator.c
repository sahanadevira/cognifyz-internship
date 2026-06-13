#include <stdio.h>

int main() {
    float a, b;
    int choice;

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Modulo\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Result = %.2f", a + b);
            break;
        case 2:
            printf("Result = %.2f", a - b);
            break;
        case 3:
            printf("Result = %.2f", a * b);
            break;
        case 4:
            if(b != 0)
                printf("Result = %.2f", a / b);
            else
                printf("Division by zero not allowed");
            break;
        case 5:
            printf("Result = %d", (int)a % (int)b);
            break;
        default:
            printf("Invalid Choice");
    }

    return 0;
}
