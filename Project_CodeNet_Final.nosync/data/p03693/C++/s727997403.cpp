#include<iostream>
using namespace std;

int main(){
    char r,g,b;
    cin >> r >> g >> b;
    int x;

    x= 100 * ( (int) r - '0' ) + 10 * ( (int) g - '0' ) +  ( (int) b - '0' );

    if( x%4 == 0 ){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}