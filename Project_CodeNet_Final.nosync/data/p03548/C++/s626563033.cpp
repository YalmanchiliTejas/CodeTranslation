#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const double PI = acos(-1);
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;

#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i = 0; i<n; i++)
#define ALL(a) begin(a), end(a)

int main (void) {
    int X,Y,Z;
    cin>>X>>Y>>Z;
    int ans = 0;
    for (int i=0;i<=X;i++) {
        if (i*Y+(i+1)*Z <= X) ans = i;
        else break;
    }
    cout<<ans<<endl;
    return 0;
}