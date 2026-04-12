#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int R1, R2;
    cin >> R1 >> R2;
    cout << fixed << setprecision(15) << 1 / (1.0 / R1 + 1.0 / R2) << endl;
}
