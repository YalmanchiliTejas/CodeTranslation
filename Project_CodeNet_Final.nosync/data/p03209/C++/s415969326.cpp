#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <random>
#include <iomanip>
#include <map>

using namespace std;

typedef long long ll;

int N;
ll X;

ll dfs(int N, ll X, vector<ll>l, vector<ll>p) {
    ll pans = 0;
    if (N == 0) {
        pans = 1;
    } else {
        if (X == 1) pans = 0;
        else if (X == 2 + l.at(N - 1)) pans = p.at(N - 1) + 1;
        else if (X == 3 + 2 * l.at(N - 1)) pans = 2 * p.at(N - 1) + 1;
        else if (X <= 1 + l.at(N - 1)) pans = dfs(N - 1, X - 1, l, p);
        else if (X <= 2 + 2 * l.at(N - 1)) pans = p.at(N - 1) + 1 + dfs(N - 1, X - l.at(N - 1) - 2, l, p);
    }
    
    return pans;
}

int main() {
    cin >> N >> X;
    
    vector<ll> l = {1};
    vector<ll> p = {1};
    for(int i = 1; i <= N; i++) {
        l.push_back(2 * l.at(i - 1) + 3);
        p.push_back(2 * p.at(i - 1) + 1);
    }
    ll ans = dfs(N, X, l, p);
    
    cout << ans << endl;
}
