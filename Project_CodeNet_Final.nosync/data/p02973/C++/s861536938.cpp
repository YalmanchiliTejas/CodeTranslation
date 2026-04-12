#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF64 = 1LL << 60;
const int INF32 = 1 << 29;
const int MOD =   1000000007;

template<class T> int LIS(vector<T> a) {
    const T INF = 1<<30; // to be set appropriately
    int n = (int)a.size();
    vector<T> dp(n, INF);
    for (int i = 0; i < n; ++i) {
        *upper_bound(dp.begin(), dp.end(), a[i]) = a[i];
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main()
{
#ifdef MYLOCAL
    ifstream in("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        int tmp; cin >> tmp;
        a[i] = -1 * tmp;
    }
    int ans = LIS(a);
    cout << ans << endl;
    return 0;
}
