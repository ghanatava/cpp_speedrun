#include <iosteram>

using namespace std;
struct Vector {
    int sz;
    double* elem;
}

void init_vector(Vector& v, int s) {
    v.elem = new double[s];
    v.sz = s;
}

double read_and_sum(int s) {
    Vector v;
    init_vector(v, s);
    for (int i = 0; i != s; ++i){
        cin >> v.elem[i];
    }
    double sum = 0;
    for (int i = 0; i != s; ++i){
        sum += v.elem[i];
    }
    return sum;
}
