#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int X;
    cin >> X;

    int flag = 0;
    if(X == 3){
       cout << "YES" << endl; 
       flag = 1;
    }
    if(X == 5){
       cout << "YES" << endl; 
       flag = 1;
    }
    if(X == 7){
       cout << "YES" << endl; 
       flag = 1;
    }

    if(flag != 1){
        cout << "NO" << endl;
    }

    return 0;
}
