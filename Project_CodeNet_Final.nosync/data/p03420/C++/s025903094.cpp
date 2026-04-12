#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
    ll n,k,ans = 0; cin >> n >> k;

    if(k == 0){
        cout << n*n;
        return 0;
    }
    for(int i = 1; i <= n; i ++){
        if(k > i-1) continue;
        else{
            ans += (n/i)*(i-1-(k-1));
            if(n%i >= k)ans += (n%i-(k-1));
        }
    }
    cout << ans;

}
