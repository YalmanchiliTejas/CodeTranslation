#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MOD = 1E9+7;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> v(n); for (ll& l : v) cin >> l;

    ll sum = accumulate(v.begin(), v.end(), 0ll, plus<ll>());
    ll result = 0;
    for (int i = 0; i < n; i++)
    {
        sum -= v[i];
        result = (result+((sum%MOD)*v[i])%MOD)%MOD;
    }
    cout << result%MOD << endl;

    return 0;
}
