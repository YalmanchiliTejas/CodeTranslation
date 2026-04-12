#include <iostream>
using namespace std;

int main(){
    int r=0, g=0, b=0;
    cin >> r >> g >> b;
    int number = 100*r + 10*g + b;
    if(number % 4 == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}