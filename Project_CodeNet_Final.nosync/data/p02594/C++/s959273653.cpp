/*
 * Lang  : C++ 17
 * Author: little_angel
 * Date  : 23-07-2020 03:45 23
 */

#include<bits/stdc++.h>

using namespace std;
#define int long long
#define sort(a) sort(a.begin(), a.end())
#define ub(a, x) upper_bound(a.begin(), a.end(), x)
#define lb(a, x) lower_bound(a.begin(), a.end(), x)
#define dbg(x) cerr<<"["<<#x<<"="<<x<<"]"
#define endl '\n'

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;

void sol() {
    int n;
    cin >> n;
    if (n >= 30)cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) sol();
}