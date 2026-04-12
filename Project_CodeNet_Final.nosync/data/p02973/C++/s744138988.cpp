#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 2e9;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    vector<int> v(n, INF);
    for (int i = 0; i < n; ++i) {
        *upper_bound(v.begin(), v.end(), a[i]) = a[i];
    }
    cout << lower_bound(v.begin(), v.end(), INF) - v.begin() << endl;
}