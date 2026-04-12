#include <bits/stdc++.h>
using namespace std;
int main(void){

    int a, b, c;
    cin >> a >> b >> c ;
    
    //*
    if( ( a * 100 + b * 10 + c ) % 4 == 0 ){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    //*/
    
    //cout << a.at(0) - 'a' + 'A' << b.at(0) - 'a' + 'A' << c.at(0) - 'a' + 'A' << endl;

    return 0; 
}
