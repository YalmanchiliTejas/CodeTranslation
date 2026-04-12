#include <iostream>
using namespace std;

int main()
{
    int r,g,b,a=0;
    cin >> r >> g >> b;
    
    a=100*r+10*g+b;
    if(a%4==0){
        cout << "YES"<<endl;
    }
    else{
        cout << "NO"<<endl;
    }
    return 0;
}