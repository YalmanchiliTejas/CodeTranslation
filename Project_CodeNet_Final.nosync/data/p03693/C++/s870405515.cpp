#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b ;
    if (b==0 && g==0 && r==0){
        cout << "NO" << endl;
    }else if (b%2==1){
        cout << "NO" << endl;
    }else if(g%2==0&&b%4==0){
        cout << "YES" << endl;
    }else if(g%2==1&&b%4==2){
        cout << "YES" << endl;
    }else if(g%2==0&&b%4==2){
        cout << "NO" << endl;
    }else if(g%2==1&&b%4==0){
        cout << "NO" << endl;
    }
    
}