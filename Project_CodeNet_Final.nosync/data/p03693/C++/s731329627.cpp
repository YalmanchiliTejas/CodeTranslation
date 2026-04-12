#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int r,g,b,num;
    cin >> r;
    cin >> g;
    cin >> b;
    num = g*10+b;
    if(num%4==0) cout << "YES" << endl;
    else cout << "NO" << endl;
}