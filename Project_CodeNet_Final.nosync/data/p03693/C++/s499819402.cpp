#include<iostream>
using namespace std;

int main(){

    int r, g, b;
    cin >> r >> g >> b;

    r *= 100;
    r += g*10;
    r += b;

    if(r%4 == 0)cout << "YES\n";
    else cout << "NO\n";

    return 0;

}