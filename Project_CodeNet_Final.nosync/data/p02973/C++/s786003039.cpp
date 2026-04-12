#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
const int inf = 1001001001;

int main() {
    int n;
    cin >> n;
    vint a(n);
    rep(i,n) cin >> a[i];
    deque<int> d;
    rep(i,n) {
        int p = lower_bound(d.begin(),d.end(),a[i]) - d.begin();
        if (p == 0) d.push_front(a[i]);
        else d[p-1] = a[i];
    }
    cout << d.size() << endl;
}