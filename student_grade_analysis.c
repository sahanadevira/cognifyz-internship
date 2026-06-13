#include <stdio.h>

int main() {
    int n;
    float marks, total = 0, highest, lowest;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        printf("Enter marks of student %d: ", i);
        scanf("%f", &marks);

        if(i == 1) {
            highest = lowest = marks;
        }

        if(marks > highest)
            highest = marks;

        if(marks < lowest)
            lowest = marks;

        total += marks;
    }

    printf("Average Marks = %.2f\n", total / n);
    printf("Highest Marks = %.2f\n", highest);
    printf("Lowest Marks = %.2f\n", lowest);

    return 0;
}
