This is a set of examples of basic pointer use

A Pointer is a variable which stores the address of another variable. The purpose of which is to allow indirect access to it, and to allow copy by reference semantics 

The pointer is a local variable and is therefore assigned onto the stack. but it can point to other varuiables, either on the stack or on the heap
```c++
  int x = 5;
  int* p = &x;
  int y = *p;
```

the unary & operator takes the address of a variable (this may also be a pointer in complex data strauctures). this is overloaded withe bainary bitwise and 
```c++
int** p2 = &p;
```

the unary * operator gets the value at the address stored in the pointer (This is overloaded with the binary multiplication form)

These overloads can be a little confusing but semantically typically make easy sense in context such that you don't get confused. 


Arrays ARE pointers to a sequential set of allocated data either in the stack or the heap

we declare the array as say
```c++
int x[5] = {0,1,2,3,4}  
int z = x[0]; // is the same as saying 
int z = *x;

// you can do arithemetic with a pointer thus
int z = x[1] // is the same as saying
int z = *(x+1);
```

its a notation convenience but the array isn't a container type. its just raw memory 
so x[5] is outside the bounds, if we're lucky it will throw a segmentation fault if we try to access it, if we're unlucky by random chance it might actually point at something valid and lead to
a truly horrible pointer error, cause that allocated memory might be anywhere in our code and tracking down what's causing the error can be real nightmare. 

## Passing Pointers into functions

one of the main use of pointers (or references see below) is to pass by reference to avoid copying. Unlike in C# for example where pass by reference or value is a compiler decision,
in C++ its down to the developer to decide so I can pass anything in by reference or by value as I see fit

```c++
void print(int* i){
 std::cout << *i << std::endl;
}

void main(){
  int i = 10;
  print(&i);
}
```

and we can therefore pass an array into a function by reference too, (obviously as its a pointer)
```c++
void printArray(int i[], size_t n){
  for(auto x = 0; x < n; x++){
    std::cout << i[x] << std::endl;
}

void main(){
  int x[5] = {0,1,2,3,4};
  printArray(x, 5);
}
```

note how the array passed in doesn;t have a size, we're not allocating an array we're passing in a reference. The contrents of the array cannot be passed by value, because it is a pointer. More importantly it 
doesn;t carry any notion of size with it, we need to pass in a correct size or risk overrunning the array, 

## dynamic memory allocation

we can assign our own data from the heap at run time using the new operator, we can allocate a single or a sequence (array) of them. This is the only way to manage varaible length arrays in raw C++ so

```c++

int *val = new int(10);
print(val);

int* x = new int[5];

// initialise the array with values
for(auto i = 0; i < 5; i++){
  x[i] = i;
}
printArray(x, 5);

delete [] x;
delete val;

```

## using references
confusingly the & is also used  in what was an early attept to tame the pointer in reference semantics. A reference is a pointer with certain additional contsrains
1) it must point to a valid allocation or null
2) it cannot change once assigned

note the use of const here, to qualify to the user that it cannot be modified. const semantics are more complicated with pointers and this is a good reason to use refereces for clarity, though the
syntax for passing an array is a little odd

```c++

void printByRef(const int& i) {
    std::cout << i << std::endl;  
}

void printArrayByRef(const int (&i)[], size_t n) {
  for(auto x = 0; x < n; x++){
    std::cout << i[x] << std::endl;
}

void main(){
  int i = 10;
  int arr[5] = {1,2,3,4,5};
  printByRef(i); // no & for address.
  printArrayByRef(arr, 5);
}

```

## using standard containers
so we have seen that in raw low level c++ if we want variable sized arrays etc, then we need to use dynamic memory management which is where the standard containers come to 
out rescue, unless we need to implementa our own ADTs. The default choice uis basically a standard template Array, that is mofe like what you expect in a langauge like Java or C#

```c++

void printVector(const std::vector<int>& v){
  for(auto i : v){
    std::cout "i = " << i << std::endl;  
  }
}


std::vector<int> x = {0,1,2,3,4};
printArray(x.data(), x.size());
printVector(x);


```



