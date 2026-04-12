#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N;
int main(){
    double R1, R2;
    cin >> R1 >> R2;
    cout << fixed << (R1*R2)/(R1+R2) << endl;
    return 0;
}