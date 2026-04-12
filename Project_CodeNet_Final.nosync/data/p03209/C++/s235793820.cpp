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

vector<ll> a,p;

ll solve(ll n, ll x){
    if(n == 0) return 1;
    else if(x == 1) return 0;
    else if(x > 1 && x <= a[n-1]+1) return solve(n-1,x-1);
    else if(x == a[n-1] + 2) return p[n-1] + 1;
    else if(x > a[n-1] + 2 && x < 2*a[n-1] + 3) return 1 + p[n-1] + solve(n-1,x-2-a[n-1]);
    else return 2*p[n-1]+1;
}

int main() {

    ll n,x; cin >> n >> x;
    a.push_back(1);
    p.push_back(1);

    rep(i,55){
        a.push_back(2*a[i]+3);
        p.push_back(2*p[i]+1);
    }


    cout << solve(n,x);

}