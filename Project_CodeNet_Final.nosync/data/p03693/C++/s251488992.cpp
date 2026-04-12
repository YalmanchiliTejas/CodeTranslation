#include <iostream>
using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b;

    int temp;
    temp = g*10 + b;

    if(temp % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;


}