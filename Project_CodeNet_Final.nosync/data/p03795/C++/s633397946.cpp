#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    double point=floor(N/15);
    cout << N*800-point*200;
    return 0;
}