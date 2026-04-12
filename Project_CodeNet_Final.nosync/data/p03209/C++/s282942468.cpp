#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%lld",&x)
vector<ll> a, p;
ll solve(ll n, ll x){
    if (n == 0 && x > 0) return 1;
    else if (n == 0 || x == 1) return 0;
    else if (x>1 && x<=a[n-1]+1) return solve(n-1, x-1);
    else if (x == a[n-1] + 2) return p[n-1]+1;
    else if (x>a[n-1]+2 && x<=a[n-1]*2+2) return p[n-1]+1+solve(n-1, x-a[n-1]-2);
    else return p[n-1]*2+1;
}
int main(){
    ll n, x; sc(n), sc(x);
    a.push_back(1ll), p.push_back(1ll);
    for (int i = 1; i <= n; i++) a.push_back(a[i-1]*2+3);
    for (int i = 1; i <= n; i++) p.push_back(p[i-1]*2+1);
    cout << solve(n, x) << endl;;
    return 0;
}