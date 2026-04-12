#include<iostream>
using namespace std;
int main(){
    int r,g,b,sum;
    cin >> r >> g >> b;
    sum = 100*r+10*g+b;
    cout << (sum%4==0?"YES":"NO") << endl;
}