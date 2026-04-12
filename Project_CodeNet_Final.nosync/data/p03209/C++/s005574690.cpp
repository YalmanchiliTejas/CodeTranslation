#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 55;
ll total[maxn], pattys[maxn];
ll n, x;

ll solve(ll l, ll level) {
    if(level == 0) return 1LL;

    ll fl = l + 1;
    ll fr = l + total[level-1];
    ll sl = l + total[level-1] + 2;
    ll sr = l + total[level-1] + 1 + total[level-1];

    if(x >= fl && x <= fr) return solve(l+1, level-1);
    else if(x >= sl && x <= sr) return pattys[level-1] + 1 + solve(sl, level-1);

    if(x == l) return 0LL;
    else if(x == fr + 1) return pattys[level-1] + 1LL;
    else if(x == sr + 1) return pattys[level];
}

int main() {
    cin>>n>>x;
    total[0] = pattys[0] = 1LL;
    for(int i=1;i<=n;i++) {
        total[i] = 3LL + 2LL * total[i-1];
        pattys[i] = 2LL * pattys[i-1] + 1LL;
    }
    cout<<solve(1, n)<<"\n";
    return 0;
}