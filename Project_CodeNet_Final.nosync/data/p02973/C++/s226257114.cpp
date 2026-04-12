#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int LAS(vector<int> &a) {
    int n = a.size();
    const int INF = 2e9;
    vector<int> dp(n, INF);
    for(int i = 0; i < n; i++) {
        auto itr = upper_bound(dp.begin(), dp.end(), a[i]);
        *itr = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    reverse(a.begin(), a.end());
    cout << LAS(a) << endl;
}