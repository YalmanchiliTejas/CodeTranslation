#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>

#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;



int main(){
    int n;
    cin >> n;
    ll all = 0;
    vector<ll> a(n);
    rep(i,n) {
        cin >> a[i];
        all += a[i];
    }

    vector<int> r(n);
    r[0] = a[0];
    for(int i = 1; i < n; i++) r[i] = r[i-1] + a[i];

    ll ans = 0;
    rep(i,n){
        ans += (a[i] % MOD) * ((all - a[i])%MOD);
        all -= a[i];
        ans %= MOD;
    }
    cout << ans << endl;
}