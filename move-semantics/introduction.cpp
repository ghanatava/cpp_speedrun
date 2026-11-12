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
};

int main() {
    Auto_ptr1<Resource> res(new Resource()); //Memory allocated
    // ... but no explicit delete needed

    // Also note that we use <Resource>, not <Resource*>
    // This is because we've defined m_ptr to have type T* (not T)

    return 0;
} // res goes out of scope here, and destroys the allocated Resource for us

