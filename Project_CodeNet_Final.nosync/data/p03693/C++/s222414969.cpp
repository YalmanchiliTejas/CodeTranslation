#include<iostream>
#define size(array) (sizeof(array) / sizeof(array[0]))
using namespace std;
int main(void){
    int a,b,c,d;
    cin >> a >> b >> c;
    d = a * 100 + b * 10 + c;
    if(d % 4 == 0){
        cout << "YES";
    }else{
        cout << "NO";
    }
}