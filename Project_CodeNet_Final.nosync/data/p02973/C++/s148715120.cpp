#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    int n;
    cin >> n;
    int a;
    vector<int> v;
    cin >> a;
    v.push_back(a);
    rep(i,n-1) {
        cin >> a;
        if (*(v.end()-1) >= a) v.push_back(a);
        else *(lower_bound(v.rbegin(), v.rend(), a) - 1) = a;
    }
    cout << v.size() << endl;
    return 0;
}