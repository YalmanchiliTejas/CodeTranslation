#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i,n) for(int i = 0;i < n;i++)
int main(){
    int n;
    long long x,a = 1,b = 1,c = 0,d = 0;
    cin >> n >> x;
    rep(i,n){
        a = 2*a + 3;
        b = 2*b + 1;
    }
    rep(i,n + 2){
        if(x == a){
            x = x - a;
            c = c + b;
        }else if(x > a){
            x = x - (a + 1);
            c = c + b + 1; 
        }
        x = x - 1;
        a = (a - 3)/2;
        b = (b - 1)/2;
    }
    cout << c << endl;
}