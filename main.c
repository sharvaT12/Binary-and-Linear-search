#include <stdio.h>
#include <stdlib.h>




//This function makes a copy of the array
void arrayCopy (int fromArray[], int toArray[], int size){

    for(int i = 0; i < size; i++){
        toArray[i] = fromArray[i];
    }

}

//This function takes an array and sorts it
void myFavorateSort (int arr[], int size){
    int i ,j, minimum;
 
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        minimum = i;
        for (j = i+1 ; j < size ; j++){

            if (arr[j] < arr[minimum]){

            minimum= j;
            }
        }


        int temp = arr[minimum] ;
        arr[minimum]  = arr[i];
        arr[i] = temp;
    }
}

//This is linear search
int linSearch (int arr[], int capacity , int target, int *numComparisons){
    int c = 0;
    
    for(int i = 0; i < capacity ; i++){
        *numComparisons = *numComparisons +1 ;
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

//Binary search
int binSearch (int arr[], int size, int target, int* numComparisons){
    
    int a = 0;
    int b = size; 

    while(b>=a){
        *numComparisons = *numComparisons +1 ;
        

        int mid = (a+b)/2;

        
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            b = mid-1;
        }
        else{
            a = mid+1;
        }

    }

    
    return -1;
}

//int main
int main(void) {

    //1st array
    int pos = 0;
    int val;

    /* prompt the user for input */
    printf ("Enter in a list of numbers followed by the terminal value of -999\n");    
    int *arr;
    int size = 100;
    arr = (int*)malloc(size*sizeof(int));
    /* loop until the user enters -999 */
    scanf ("%d", &val);
    while (val != -999){
        if (pos>= size){
            int *temp = arr;
            arr = (int*)malloc(size*2*sizeof(int));
            for(int j = 0; j < size ; j++){
                arr[j] = temp[j];
            }
            free(temp);
            size = size * 2;           
        }
        arr[pos] = val;       
        pos = pos + 1; 
        scanf("%d", &val);
    }

    //sorting the array
    int *sorted = (int*)malloc(size*sizeof(int));
    arrayCopy (arr, sorted, pos);

    myFavorateSort (sorted, pos);



    /* users 2nd input */
    printf ("Enter in a list of numbers followed by the terminal value of -999\n");    
    int *arr2;
    int capacity = 100;
    int val_comp;
    int index = 0;
    arr2 = (int*)malloc(capacity*sizeof(int));
    /* loop until the user enters -999 */
    scanf ("%d", &val_comp);
    while (val_comp != -999){
        if (index>= capacity){
            int *temp = arr2;
            arr2 = (int*)malloc(capacity*2*sizeof(int));
            for(int j = 0; j < capacity ; j++){
                arr2[j] = temp[j];
            }
            free(temp);
            capacity = capacity * 2;           
        }
        arr2[index] = val_comp;       
        index = index + 1; 
        scanf("%d", &val_comp);
    }

    
    
    for(int s = 0; s < index ; s ++){
       int comparisons = 0;
       int lin = linSearch (arr , pos, arr2[s], &comparisons);
       
       int comparisons_2 = 0;
       int bin = binSearch (sorted,pos, arr2[s], &comparisons_2);

       if(lin == -1){
           printf("The value %d was not found in the array\n",arr2[s]);
           printf("The number of comparisons via Linear = %d\n",comparisons);
           printf("The number of comparisons via Binary = %d\n",comparisons_2);
       }
       else{
           printf("The value %d was found in the array\n", arr2[s]);
           printf("The number of comparisons via Linear = %d\n",comparisons);
           printf("The position in Linear search = %d\n",lin);

           printf("The number of comparisons via Binary = %d\n",comparisons_2);
           printf("The position in Binary search = %d\n",bin);
       }

       printf("\n");

    }




    free(arr);
    free(sorted);
    free(arr2);
    return 0;
}