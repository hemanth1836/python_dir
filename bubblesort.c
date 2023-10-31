#include <stdio.h>

// Function to print array 
void display(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

// Main function to run the program
int main() 
{ 
    int array[] = {5, 3, 1, 9, 8, 2, 4,7}; 
    int size = sizeof(array)/sizeof(array[0]); 

    printf("Before bubble sort: \n");
    display(array, size);

    int i, j, temp; 
    for (i = 0; i < size-1; i++){       

       // Since, after each iteration right-most i elements are sorted   
       for (j = 0; j < size-i-1; j++) 
           if (array[j] > array[j+1]) 
           {
              temp = array[j]; // swap the element
              array[j] = array[j+1]; 
              array[j+1] = temp; 
           }
    }
    printf("After bubble sort: \n"); 
    display(array, size); 
    return 0; 
}
Output
After Sorted Element List

Before bubble sort
5 3 1 9 8 2 4 7 
After bubble sort:
1 2 3 4 5 7 8 9
Example Bubble Sort in C – 1
Method 2
The above code isn’t optimized for if the array is already sorted or nearly sorted.

Even if the array is sorted in the above (method 1) code the time complexity for the best case will still be O(N2).

This can be resolved using a flag variable that changes its value if there was no swapping in any of the passes.
This reduces the best case time complexity (when the array is already sorted) to O(N)
For example -
arr[]  = {10, 20, 30, 40, 50}
This array is already sorted still the above bubble sort code will run all the passes and iterations anyways.

arr[]  = {10, 20, 30, 100, 50}
Even for this array which has one single item '100' out of place will get sorted in the first pass itself. Still, all passes and iterations will run.

This can be resolved by changing the code as below by introducing a flag variable

Prime Course Trailer

Related Banners
Get PrepInsta Prime & get Access to all 200+ courses offered by PrepInsta in One Subscription

Get Prime
Code Method 2
If there is any pass where no swap happens, do not implement any further passes since the array is already sorted.

Run
#include <stdio.h>

void swap(int *var1, int *var2) 
{ 
    int temp = *var1; 
    *var1 = *var2; 
    *var2 = temp; 
} 

// Here we are implementing bubbleSort
void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++){
        // initializing swapped to 0 (no swaps happenned yet)
        int swapped = 0;

       // Since, after each iteration righmost i elements are sorted   
        for (j = 0; j < n-i-1; j++) { 
            if (arr[j] > arr[j+1]) 
            {
                swap(&arr[j], &arr[j+1]);
                // change swap value as swap has happenned
                swapped = 1;
            }
        }
        // if no swaps happen stop don't impliment further passes/iterations
        if(!swapped)
            break;
    }
} 

/* Function to print array */
void display(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

// Main function to run the program
int main() 
{ 
    int array[] = {10, 20, 30, 40, 50}; 
    int size = sizeof(array)/sizeof(array[0]); 

    printf("Before bubble sort: \n");
    display(array, size); 

    bubbleSort(array, size);

    printf("After bubble sort: \n"); 
    display(array, size); 
    return 0; 
}
Output
Before bubble sort: 
10 20 30 40 50 
After bubble sort: 
10 20 30 40 50
Performance-Based Analysis of Bubble Sort Algorithm
Pros
Easy to implement
Cool to implement
Gives the largest value of the array in the first iteration itself.
Or the smallest value of array in the first iteration itself (Minor tweak in implementation)
No demand for large amounts of memory for operation
Cons
Noob (Bad) algorithm 😀
Very horrible time complexity of O(n2)
Interesting Facts
Average and worst-case time complexity: o(n2)
Best case time complexity: n when the array is already sorted.
Worst case: when the array is reverse sorted.
Number of comparisons in Bubble sort is reduces by 1 in each pass.

Example – For array size 5, 

In Pass 1: 4 comparisons
In Pass 2: 3 comparisons
In Pass 3: 2 comparisons
In Pass 4: 1 comparison
Thus, for n sized array the total number of comparisons, therefore, is (n – 1) + (n – 2)…(2) + (1) = n(n – 1)/2 

Bubble sort meme 1

Time Complexity
For Bubble Search
Best
Ω(n)

Average
Θ(n2)

Worst
O(n2)

Space Complexity
O(1)


Sorting
Sorting algorithms are easy to learn but are really important for college semester exams and companies offering package between 3 – 6 LPA would ask direct searching questions in online test/ interviews.

Classification of Sorting Algorithms
Bubble Sort  – C | C++ | Java
Insertion Sort – C | C++ | Java
Selection Sort – C | C++ | Java
Merge Sort – C | C++ | Java
Quick Sort – C | C++ | Java
Counting Sort – C | C++ | Java
Radix Sort – C | C++ | Java
Heap Sort – C | C++ | Java
Data Structures and Algorithm Learn Sorting
Login/Signup to comment


PrepInsta.com
No.1 and most visited website for Placements in India.

We help students to prepare for placements with the best study material, online classes, Sectional Statistics for better focus and Success stories & tips by Toppers on PrepInsta.

© 2023 Prep Insta
Support
Contact Us
About Us
Refund Policy
Privacy Policy
Services 
Disclaimer
Terms and Conditions

Companies
Accenture
Cognizant
MindTree
VMware
CapGemini
Deloitte
WiproMicrosoft
TCS
Infosys
Oracle
HCL
TCS Ninja
IBM
All Exams Dashboards
CoCubes Dashboard
eLitmus Dashboard
HirePro Dashboard
MeritTrac Dashboard
Mettl Dashboard
DevSquare Dashboard

Get In Touch
Instagram
Linkedin
Youtube
Telegram
Facebook
Twitter
Get In Touch
 support@prepinsta.com
+91-8448440710
Text us on Whatsapp/Instagram

Privacy Policy | Copyright © 2023 Prep Insta
