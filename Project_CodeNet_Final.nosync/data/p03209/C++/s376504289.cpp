#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

ll solve(ll level, ll layer) {
    if(level == 0) return 1;
    ll len = (1LL << (level + 1)) - 3;
    ll num = (1LL << level) - 1;
    if(layer <= 1) return 0;
    if(layer <= 1 + len) return solve(level - 1, layer - 1);
    if(layer == 2 + len) return num + 1;
    if(layer <= 2 + len + len) return num + 1 + solve(level - 1, layer - (2 + len));
    return num * 2 + 1;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);
    
    int n;
    ll x;
    cin >> n >> x;
    cout << solve(n, x) << endl;

    return 0;
}