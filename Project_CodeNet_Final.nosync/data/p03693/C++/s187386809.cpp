#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
typedef long long i64;
int main(){
    int r,g,b;
    cin >> r >> g >> b;
    cout << ((g*10+b)%4==0 ? "YES":"NO") << endl;
    return 0;
}
