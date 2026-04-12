#include "bits/stdc++.h"
using namespace std;
int INF = numeric_limits<int>::max() / 2;
using ll = long long;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    y = x;
    sort(y.begin(), y.end());
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        if(i < n/2) mp[y[i]] = y[n/2];
        else mp[y[i]] = y[n/2-1];
    }
    for(int i = 0; i < n; i++){
        cout << mp[x[i]] << '\n';
    }
    return 0;
}