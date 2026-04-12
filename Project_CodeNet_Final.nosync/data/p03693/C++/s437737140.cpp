#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int r,g,b;
    int Z;
    cin>>r>>g>>b;
    Z = (g * 10) + b;
    //条件分岐→[if]
    if(Z % 4 == 0){
        cout << "YES" <<endl;
    }
    else{
        cout <<"NO" <<endl;
    }
}


//=代入
// == 