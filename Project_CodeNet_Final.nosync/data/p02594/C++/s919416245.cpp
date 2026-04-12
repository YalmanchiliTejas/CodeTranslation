//#pragma GCC optimize (2)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii =  pair<int,int>;
const int  dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
const int mod = 1000000007;
const int INF = 0x3f3f3f;
#define all(v) v.begin(),v.end()
ll quick_pow(ll base, ll n) {
    ll ans = 1;
    while (n ) {
        if (n & 1 )
            ans *= base;
        base *= base;
        n >>= 1;
    }
    return ans;
}
void solve();
int main() {
    int T=1;
//    cin>>T;
    while (T--){
        solve();
    }
    return 0;
}
void solve() {
    int x;
    cin>>x;
    cout<<(x>=30?"Yes":"No")<<endl;
}
