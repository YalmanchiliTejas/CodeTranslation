#include <iostream>
using namespace std;
int main(void){
    int r;
    int g;
    int b;
    cin >> r >> g>> b ;
    if ((10*g+b)%4 == 0){
    cout << "YES" <<endl;
    }
    else {
        cout << "NO" <<endl;
    }
}
