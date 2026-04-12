#include <bits/stdc++.h>
using namespace std;

int main(){
    //入力
    int r,g,b;
    cin >> r >> g >> b;
    //出力
    if((100*r+10*g+b)%4==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    
}