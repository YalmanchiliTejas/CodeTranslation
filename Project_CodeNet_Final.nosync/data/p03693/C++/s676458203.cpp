#include<iostream>
using namespace std;

int main(){
    int r = 0, g = 0, b = 0;
    cin >> r >> g >> b;
    cout << (((r * 100 + g * 10 + b) % 4) ? "NO" : "YES") << endl;
}