#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double r1, r2;
    cin >> r1 >> r2;
    cout << fixed;
    cout << setprecision(10);
    cout << (r1*r2)/(r1+r2) << endl;
    return 0;
}
