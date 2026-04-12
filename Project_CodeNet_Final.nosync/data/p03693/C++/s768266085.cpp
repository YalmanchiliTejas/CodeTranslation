#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int r,b,g;
    cin >> r >> b >> g;
    int rbg = 100 * r + 10 * b + g;
    if(rbg % 4 == 0 ){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
