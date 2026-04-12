#include <iostream>

using namespace std;

int main() {
    int a , b , c;
    cin >> a >> b >> c;
    int r(0);
    while( a - r*(b+c) - c >= b + c){
        r++;
    }
    cout << r;
}

