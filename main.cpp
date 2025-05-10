/* SImple Pointer example, using the C Standard Library 

Theres a lot in here and so Ill take it bit by bit with commentary 

*/


#include <stdio.h>
#include <stdlib.h>
#include <vector>

void basics(){
    printf("The Basics of Pointers\n");
    // when we declare an integer variable, it is stored in the stack
    int n = 5; 
    
    // when we declare a pointer variable, it is stored in the stack
    int *p = &n; // p is a pointer to n, it stores the address of n 
    
    // as an aside the address operator & is also used for reference variables 
    // when we declare a reference variable, it is stored in the stack
    int &r = n; // r is a reference to n, it stores the address of n

    // this is a confusion in C++ because the address operator & is used for both pointers and references 
    // and I just wanted to make you aware of it. You can kind of think of it as being the address of the variable
    // whereas a pointer is a variable that stores the address of another variable

    // what this means is that when you define a reference it has to point to valid object or nullptr and cannot change 
    printf("n = %d\n", n); // prints 5
    printf("p = %d\n", *p); // prints 5


    int m = 10;
    r = m; // this is a copy assignment, it copies the value of m to n, not the address of m to n

    // the primary uae of references is to pass variables by reference to functions in a slightly more user friendly way to pointers

    // anyway back to pointers

    // we can dereference a pointer to get the value of the variable it points to
    printf("n = %d\n", n); // prints 10
    printf("p = %d\n", *p); // prints 10
    printf("r = %d\n", r); // prints 10
}

void arrays(){
    printf("Arrays and Pointers\n");
    // when we declare an array, it is stored in the stack
    int arr[5] = {1, 2, 3, 4, 5}; // arr is a pointer to the first element of the array

    // when we declare a pointer to an array, it is stored in the stack
    int *p = arr; // p is a pointer to the first element of the array

    // we can dereference a pointer to get the value of the variable it points to
    printf("arr[0] = %d\n", arr[0]); // prints 1
    printf("p[0] = %d\n", *p); // prints 1
}

void pointer_arithmetic(){
    printf("Pointer Arithmetic\n");
    // pointer arithmetic is the ability to perform arithmetic operations on pointers
    // this is useful for iterating over arrays and other data structures

    int arr[5] = {1, 2, 3, 4, 5}; // arr is a pointer to the first element of the array
    int *p = arr; // p is a pointer to the first element of the array

    // we can use pointer arithmetic to iterate over the array
    for(int i = 0; i < 5; i++){
        printf("arr[%d] = %d\n", i, *(p + i)); // prints 1, 2, 3, 4, 5
    }

    // care should be taken when using pointer arithmetic 
    // because it can lead to undefined behavior if you go out of bounds of the array etc
}

void dynamic_memory(){
    printf("Dynamic Memory Allocation\n");
    
    // dynamic memory allocation is the ability to allocate memory on the heap at runtime
    // this is useful for creating data structures that can grow and shrink in size
    
   // the pointer to the first element of the array is stored in the stack
   // but the array itself can be stored in the stack or the heap

    // when we declare an array, it is stored in the stack
    int arr[5] = {1, 2, 3, 4, 5}; // arr is a pointer to the first element of the array
    
    // however we can also allocate memory for an array on the heap using the new operator
    int *p = new int[5]; // p is a pointer to the first element of the array on the stack, the 
    // array itself is stored in the heap
    
    // however we then need to initialise the array ourselves
    for(int i = 0; i < 5; i++){
        p[i] = i + 1; // p is a pointer to the first element of the array
    }
    
    // using the dynamic array is the same as using a normal array
    for(int i = 0; i < 5; i++){
        printf("arr[%d] = %d\n", i, p[i]); // prints 1, 2, 3, 4, 5
    }

    // when we are done with the array we need to free the memory using the delete operator
    delete[] p; // free the memory allocated for the array

}

void some_modern_cpp(){
    printf("Some Modern C++ features\n");
    // in modern c++ we have some new features that make working with pointers and arrays easier
    int arr[5] = {1, 2, 3, 4, 5}; // arr is a pointer to the first element of the array
    
    for(int x : arr){ // range based for loop like foreach in C#
        printf("arr = %d\n", x); // prints 1, 2, 3, 4, 5
    }

    // vectors are a dynamic array that can grow and shrink in size
    // they are part of the standard template library (STL) and are very useful for working with dynamic arrays
    std::vector<int> vec = {1, 2, 3, 4, 5}; // vec is a vector of integers
    
    // we can use the same range based for loop to iterate over the vector
    for(int x : vec){ // range based for loop like foreach in C#
        printf("vec = %d\n", x); // prints 1, 2, 3, 4, 5
    }
    // we can also use the vector like an array in a classic for loop
    for(int i = 0; i < vec.size(); i++){
        printf("vec[%d] = %d\n", i, vec[i]); // prints 1, 2, 3, 4, 5
    }

    // the vector class also has some useful methods for working with dynamic arrays
    // we can add elements to the vector using the push_back method
    vec.push_back(6); // add 6 to the end of the vector
    vec.push_back(7); // add 7 to the end of the vector

    // this last thing takes a little explaining 
    // c++ has a type called iterator which is basically an abstraction for a pointer
    // it allows us to iterate over the elements of a container (like a vector) without having to worry about the underlying implementation
    // we can use the begin and end methods to get iterators to the first and last elements of the vector
    // we can then use the iterator to access the elements of the vector and a bit of pointer arithmetic
    // in this case end points to the element one after the end of the array so we need to subtract 1 from it to get the last element
    printf("vec[7] = %d\n", *(vec.end() -1)); // prints 7

    // we can use the iterator to iterate over the elements of the vector, 
    // which is why the end method returns an iterator one past the end of the vector
    for(auto it = vec.begin(); it != vec.end(); it++){
        printf("vec = %d\n", *it); // prints 1, 2, 3, 4, 5, 6, 7
    }
    // the beauty of the vector is that it wraps the memory management for us
    // it sits on the stack and the elements are stored in the heap
    // when we are done with the vector we dont need to free the memory, it is done for us
}

int main(){
    basics();
    arrays();
    pointer_arithmetic();
    dynamic_memory();
    some_modern_cpp();
    exit(EXIT_SUCCESS); // unix exit function

}