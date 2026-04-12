#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    int r,g,b,nm;
    cin >> r >> g >> b;
    nm = 100*r + 10*g + b;
    if(nm%4==0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
