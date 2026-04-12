#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << n*800 - (int)floor(n/15)*200 << endl;
}