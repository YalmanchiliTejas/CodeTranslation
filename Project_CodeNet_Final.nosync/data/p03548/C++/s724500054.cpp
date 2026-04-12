#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    int X, Y, Z;
    cin >> X >> Y >> Z;
    X -= Z;
    int a = Z + Y;
    int ans = X / a;
    cout << ans << endl;
}