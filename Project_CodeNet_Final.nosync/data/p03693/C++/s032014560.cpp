#include <iostream>
using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    int p = g*10 + b;
    if(p % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}