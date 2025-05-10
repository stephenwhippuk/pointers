This is a set of examples of basic pointer use

A Pointer is a variable which stores the address of another variable. The purpose of which is to allow indirect access to it, and to allow copy by reference semantics 

The pointer is a local variable and is therefore assigned onto the stack. but it can point to other varuiables, either on the stack or on the heap

- int x = 5;
- int* p = &x;
- int y = *p;

the unary & operator takes the address of a variable (this may also be a pointer in complex data strauctures). this is overloaded withe bainary bitwise and 
- int** p2 = &p;

the unary * operator gets the value at the address stored in the pointer (This is overloaded with the binary multiplication form)

These overloads can be a little confusing but semantically typically make easy sense in context such that you don't get confused. 


Arrays ARE pointers to a sequential set of allocated data either in the stack or the heap

we declare the array as say
int x[5] = {0,1,2,3,4} 

but 
int z = x[0] is the same as saying 
int z = *x;

you can do arithemetic with a pointer thus
int z = x[1] is the same as saying
int z = *(x+1);

its a notation convenience but the array isn't a container type. its just raw memory 
so x[5] is outside the bounds, if we're lucky it will throw a segmentation fault if we try to access it, if we're unlucky by random chance it might actually point at something valid and lead to
a truly horrible pointer error, cause that allocated memory might be anywhere in our code and tracking down what's causing the error can be real nightmare. 


