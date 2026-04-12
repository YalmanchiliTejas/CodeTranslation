#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int r,g,b;
    cin >> r >> g >> b;
    int a=10*g+b;
    if(a%4==0)cout << "YES" << endl;
    else cout << "NO" << endl;    
}