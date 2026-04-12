#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000000007LL;
const int INF = LLONG_MAX;

int solve(int x, int L, vector<pair<int, int> > &f){
    int len = f[L - 1].first + f[L - 1].second;
    if(x == 1 && L == 0) return 1;
    if(x == 1) return 0;
    else if(x < len + 2) return solve(x - 1, L - 1, f);
    else if(x == len + 2) return 1 + f[L - 1].second;
    else if(x < 2 * len + 3) return 1 + f[L - 1].second + solve(x - (len + 2), L - 1, f);
    else return 1 + 2 * f[L - 1].second;
}

signed main(){

    int n, x; cin >> n >> x;
    vector<pair<int, int> > f(n + 1);
    f[0] = {0, 1};
    for(int i = 0; i < n; i++){
        f[i + 1].first = 2 * f[i].first + 2;
        f[i + 1].second = 2 * f[i].second + 1;
    }

    cout << solve(x, n, f) << endl;

    return 0;
}