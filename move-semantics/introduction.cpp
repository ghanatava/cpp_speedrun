#include <iostream>

template <typename T>
class Auto_ptr1{
    T* m_ptr{};
    public:
        //Pass in a pointer to own via the constructor
        Auto_ptr1(T* ptr=nullptr):m_ptr(ptr){} //T* ptr=nullptr is a default argument

        //Destructor will make sure to clean it up
        ~Auto_ptr1(){
            delete m_ptr;
        }
        // Overload dereference and operator-> so we can use Auto_ptr1 like m_ptr.
        T& operator*() const { return *m_ptr; }
        T* operator->() const { return m_ptr; }
};

class Resource {
    public:
        Resource(){ std::cout << "Resource acquired \n"; } //nullptr example
        ~Resource(){ std::cout << "Resource released \n"; }
        void sayHi() { std::cout << "Hi\n"; }
};

void someFunction() {
    Auto_ptr1<Resource> ptr(new Resource()); //pointer now owns the resource(the object)
    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;
    if (x==0) return;
    ptr->sayHi();  //just like a method is called
}

int main() {
    Auto_ptr1<Resource> res(new Resource()); //Memory allocated
    // ... but no explicit delete needed

    //Auto_ptr1<Resource> res1(new Resource());
    //Auto_ptr1<Resource> res2(res1); // Alternatively, don't initialize res2 and then assign res2 = res1; this will crash a double free()

    // Also note that we use <Resource>, not <Resource*>
    // This is because we've defined m_ptr to have type T* (not T)
    someFunction();
    return 0;
} // res goes out of scope here, and destroys the allocated Resource for us

