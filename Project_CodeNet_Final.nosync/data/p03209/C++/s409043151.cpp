#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

vector<int> patties, size;

int solve(int layers, int L) {
    if(layers <= 0) return 0;
    if(L == 0) {
        return 1;
    }
    layers--;
    if(layers == size[L-1]) {
        return patties[L-1];
    }
    if(layers < size[L-1]) {
        return solve(layers, L-1);
    }
    return patties[L-1] + 1 + solve(layers-size[L-1]-1, L-1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    cin >> n >> x;
    size.resize(n+1);
    patties.resize(n+1);
    size[0] = 1;
    patties[0] = 1;
    for(int i = 1; i <= n; ++i) {
        size[i] = 2*size[i-1] + 3;
        patties[i] = 2*patties[i-1]+1;
    }
    cout << solve(x, n) << '\n';
    return 0;
}


























