#include <iostream>
#include <ctime>
using namespace std;

//declaring functions
void set_array_length(int&);
void populate_array(int, int*);
void print_array(int, int*);
void copy_array(int, int*, int*);
void print_new_array(int, int*);
void mergeSort(int arr[], int, int, int);
void merge(int arr[], int, int, int, int);
void print_sorted_array(int, int*);
int find_primes(int arr[], int);


int main(){
    srand(time(NULL));
    int array_length;

    //defining array pointers
    int * array;
    array = new int[array_length];

    int * new_array;
    new_array = new int[array_length];

    //calling functions to execute program
    set_array_length(array_length);
    populate_array(array_length, array);
    print_array(array_length, array);
    copy_array(array_length, array, new_array);
    print_new_array(array_length, new_array);

    //sorting the array and printing the sorted array
    mergeSort(new_array, 0, array_length - 1, array_length);
    print_sorted_array(array_length, new_array); //prints the sorted array

    //finding & printing prime numbers from the sorted array
    cout << "Total number of prime numbers is: ";
    cout << find_primes(new_array, array_length) << endl << endl;

    return 0;
}

//function to get array length, pass by reference
void set_array_length(int &arr_len){
    int user_input;
    int error_count = 0;
    string temp_val;
    do{
        error_count = 0;
        cout << "Enter size of the array: ";
        cin >> temp_val;
        cout << endl;
        for(int i = 0; i < 1; i++){
            if(!isdigit(temp_val.at(i)) || stoi(temp_val) <= 0 || stoi(temp_val) > 20 ){error_count++;}
        }
        if(error_count != 0){cout << "Invalid input. Try again!" << endl;}
    }while(error_count != 0);
    user_input = atoi(temp_val.c_str()); 
    arr_len = user_input;
}

//function to populate array
void populate_array(int a, int* arry){
    int random_number;
    for(int i = 0; i < a; i++){
        random_number = rand() % 50 + 1;
        arry[i] = random_number;
    }
}

//function to print array
void print_array(int your_array, int* parry){
    cout << "Here's your array: " << endl;
    for(int j = 0; j < your_array; j++){
        cout << parry[j] << " ";
    }
    cout << endl << endl;
}

//function to print the sorted array
void print_sorted_array(int ar_num, int* parry){
    cout << "The sorted array: " << endl;
    for(int j = 0; j < ar_num; j++){
        cout << parry[j] << " ";
    }
    cout << endl << endl;
}

//function to copy the old array to the new array
void copy_array(int length, int* the_old, int* the_new){
    for(int b = 0; b < length; b++){
        the_new[b] = the_old[b];
    }
}

//function to print the new array
void print_new_array(int new_length, int * n_array){
    cout << "Your copied array is:" << endl;
    for(int c = 0; c < new_length; c++){
        cout << n_array[c] << " "; 
    }
    cout << endl << endl;
}

void merge(int arr[], int left, int mid, int right, int size)
{
    int i = left, k = left;
    int j = mid + 1;
    

    int temp_array[size]; //creating a temporary array

    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp_array[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp_array[k] = arr[j];
            j++;
            k++;
        }
    }
    
    while(i <= mid){ // Copy over the remaining elements of first half
        temp_array[k] = arr[i];
        i++;
        k++;
    }

    while(j <= right){ // Copy over the remaining elements of second half
        temp_array[k] = arr[j];
        j++;
        k++;
    }

    for(int p = left; p <= right; p++){ // Copy over the temp array to original array
        arr[p] = temp_array[p]; // now our new sorted array is ready to be printed
    }
}


void mergeSort(int arr[], int left, int right, int size)
{
    if (left < right){
        int mid = (left + right) / 2; //getting the middle of the array
        mergeSort(arr, left, mid, size);
        mergeSort(arr, mid + 1, right, size);
        merge(arr, left, mid, right, size);
    }
}

int find_primes(int arr[], int the_count){ //function to determine prime numbers from the static array
    int prime_count = 0;
    for(int n = 0; n < the_count; n++){
        bool isPrime = true;
        if (arr[n] <= 0 || arr[n] == 1){isPrime = false;}
        else{
            for(int i = 2; i <= arr[n] / 2; ++i){
                if (arr[n] % i == 0) {isPrime = false; break;}
            }
        }
        if(isPrime){prime_count = prime_count + 1;}
    }
    
    return prime_count;
}

