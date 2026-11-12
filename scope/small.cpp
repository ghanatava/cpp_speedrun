#include <iostream>
#include <cstdint>
int main(){

    int16_t smaller{};
    int16_t larger{};
    std::cout << "Enter an integer:" ;
    std::cin >> smaller;
    std::cout << "Enter a large idiot integer:" ;
    std::cin >> larger;

    if (smaller > larger){
        std::cout << "you got it wrong idiot, I will fix it for you";
        int16_t tmp {};
        tmp = smaller;
        smaller = larger;
        larger = tmp;
        //tmp dies here
    }
    std::cout << "Larger is " << larger << "\n";
    std::cout << "Smaller is " << smaller << "\n";
    return 0;
}  // smaller and larger dies here.
