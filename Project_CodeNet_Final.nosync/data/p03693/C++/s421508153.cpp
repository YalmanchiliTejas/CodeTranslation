#include <bits/stdc++.h>
using namespace std;
//#define int long long

signed main(){
    int r,g,b;
    cin >>r>>g>>b;
    int k=100*r+10*g+b;
    if(k%4==0)cout << "YES";
    else cout <<"NO";
    return 0;
}