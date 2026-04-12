#include<iostream>
using namespace std;

int main(){
    int X;
    cin >> X;
    
    cout << ((X%2==1&&X!=1&&X!=9)?"YES":"NO") << endl;
    return 0;
}