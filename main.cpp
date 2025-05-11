/* SImple Pointer example, using the C Standard Library 

Theres a lot in here and so Ill take it bit by bit with commentary 

*/


#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <memory>

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

void printArray(int i[], size_t n){
    // this is a function that takes an array and its size as arguments
    // it prints the elements of the array
    for(size_t x = 0; x < n; x++){
        printf("arr[%zu] = %d\n", x, i[x]); // prints 1, 2, 3, 4, 5
    }
}

void printArrayByReference(const int (&i)[] , size_t n) {
    // this is a function that takes an array by reference
    // it prints the elements of the array
    for(size_t x = 0; x < n; x++){
        printf("arr[%zu] = %d\n", x, i[x]); // prints 1, 2, 3, 4, 5
    }
}

void printVector(const std::vector<int>& vec) {
    // this is a function that takes a vector by reference
    // it prints the elements of the vector
    for(size_t x = 0; x < vec.size(); x++){
        printf("vec[%zu] = %d\n", x, vec[x]); // prints 1, 2, 3, 4, 5
    }
}

void prinVectorByPointer(const std::vector<int>* vec) {
    // this is a function that takes a vector by pointer
    // it prints the elements of the vector
    for(size_t x = 0; x < vec->size(); x++){
        printf("vec[%zu] = %d\n", x, (*vec)[x]); // prints 1, 2, 3, 4, 5
    }
}

void smartPointers(){
    printf("Smart Pointers\n");
    // smart pointers are a new feature in C++11 that make working with pointers easier
    // they are part of the standard template library (STL) and are very useful for working with dynamic arrays
    // they automatically manage the memory for us and free it when we are done with it
    // there are two types of smart pointers: unique_ptr and shared_ptr

    // unique_ptr is a smart pointer that owns a single object and cannot be copied
    // it is used for objects that have a single owner
    std::unique_ptr<int> p1(new int[5]); // p1 is a unique_ptr to an integer
    // initialise the array with the values 1, 2, 3, 4, 5
    for(int i = 0; i < 5; i++){
        *(p1.get() + i)= i + 1; // p1 is a pointer to the first element of the array
    }
    // shared_ptr is a smart pointer that can be shared between multiple owners
    // it is used for objects that have multiple owners
    std::shared_ptr<int> p2(new int[5]); // p2 is a shared_ptr to an integer
    for(int i = 0; i < 5; i++){
        *(p2.get() + i)= i + 1; // p1 is a pointer to the first element of the array
    }

    // access is a little more complicated than a normal pointer 
    // we can use the get() method to get the raw pointer to the object
    // we can also use the dereference operator * to get the value of the object

    printf("p1 = %d\n", *p1); // prints 5
    printf("p2 = %d\n", *p2); // prints 5

    printArray(p1.get(), 5); // prints 1, 2, 3, 4,5
    printArray(p2.get(), 5); // prints 1, 2, 3, 4,5

    // however the payoff is that we dont need to worry about freeing the memory

    // there are also weak pointers which are used to break circular references
    // they are not used as often but are useful in some cases

    std::weak_ptr<int> p3(p2); // p3 is a weak_ptr to an integer
    // weak_ptr does not own the object and does not free the memory

    printArray(p3.lock().get(), 5); // prints 1, 2, 3, 4,5
    // the lock() method returns a shared_ptr to the object if it is still valid
    // otherwise it returns a nullptr
}





int main(){
    basics();
    arrays();
    pointer_arithmetic();
    dynamic_memory();
    some_modern_cpp();

    int arr[5] = {1, 2, 3, 4, 5}; // arr is a pointer to the first element of the array
    printArray(arr, 5); // prints 1, 2, 3, 4, 5
    printArrayByReference(arr, 5); // prints 1, 2, 3, 4, 5

    smartPointers();
    exit(EXIT_SUCCESS); // unix exit function

}