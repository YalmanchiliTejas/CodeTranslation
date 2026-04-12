#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
using namespace std;
signed main(){
    int x,y,z;
    cin >> x >> y >> z;
    x -= z;
    y += z;
    cout << x/y << endl;
    return 0;
}