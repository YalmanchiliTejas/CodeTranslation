#include <iostream>
using namespace std;
int main(){
    int r,g,b;
    cin >> r >> g >> b;
    if((100*r + 10*g + b)%4){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }
}
