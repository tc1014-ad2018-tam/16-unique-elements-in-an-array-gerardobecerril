/*
 * This program lets the user input as many numbers as he wants, then tells him or her how many unique numbers
 * were found.
 *
 * Author: Gerardo González Becerril.
 * E-mail: a01411981@itesm.mx
 * Date: October 14th, 2018.
 */

 // Libraries needed.
 #include <stdio.h>
#include <stdlib.h>

// Function used for the 'qsort' function that compares two numbers.
int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main() {

    int x; // Variable that takes user input.
    int n; // Variable that stores how many numbers the user wants.
    int counter; // Variable that stores how many duplicates of a number there are.
    int repetition; // Variable used to determine whether another while loop will take place or not.

    // Asks the user how many numbers he or she will want.
    printf("How many numbers would you like?\n");
    scanf("%i", &n);

    int arr[n]; // Array with the size needed to fit the numbers.

    printf("Give me %i numbers:\n", n);

    // For loop that asks for a value, then inserts it into the corresponding position in the array.
    for (int i = 0; i < n; i++) {
        printf("Give me number %i:\n", i + 1);
        scanf("%i", &x);
        arr[i] = x;
    }

    // Sorts the numbers in the array from smallest to biggest.
    qsort(arr, n, sizeof(int), cmpfunc);

    printf("The unique numbers are:\n");

    // For loop that prints the unique numbers.
    for (int i = 0; i < n; i += counter+1) {

        counter = 0; // Restarts the amount of duplicates found each time there is a new number being checked.

        // While loop that compares a number with the following one.
        do {
            // Compares the number in the current position with the next one or the one after, etc.
            if (arr[i] == arr[i+counter+1]) {
                counter++; // A duplicate was found.
                repetition = 1; // Another loop is required.
            } else {
                repetition = 0; // No duplicate was found. No more loops required.
            }
        } while (repetition == 1);

        // If no duplicates were found, the number is unique and should be printed.
        if (counter == 0) {
            printf("%i\n", arr[i]);
        }

    }

    return 0;

}