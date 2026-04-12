#include<iostream>
using namespace std;

int main(){
    int r,g,b;
    cin >> r >> g >> b;
    int s=0;
    s = r*100+g*10+b*1;

    if(s%4==0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}