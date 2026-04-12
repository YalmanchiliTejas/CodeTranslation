//064 A - RGB Cards 2017/06/10
#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
using namespace std;
typedef long long int int64;
typedef unsigned long long uint64;

int main(){
    int r , g , b; cin >> r >> g >> b;
    int num = r * 100 + g * 10 + b;
    cout << ( num % 4 == 0 ? "YES" : "NO" ) << endl;
}