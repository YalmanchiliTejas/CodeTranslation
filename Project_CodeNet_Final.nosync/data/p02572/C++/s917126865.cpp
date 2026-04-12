#include <bits/stdc++.h>
using namespace std;
 
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)

#define ll long long

const int MOD = 1e9 + 7;

int main() {

	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.in", "r", stdin);

    int n;
    cin>>n;
    std::vector<int> a(n);
    int i;

    ll baza = 0ll;

    for (i=0;i<n;i++) {
        cin>>a[i];
        if (i>0) baza+=a[i];
        baza %= MOD;
    }

    ll vk = (baza * a[0]) % MOD;

    // cout<<vk<<"\n";

    int j;
    for (j=1;j<n;j++) {
        baza -= a[j];
        baza += MOD;
        baza %= MOD;

        vk+= (a[j] * baza) % MOD;
        vk%=MOD;
    }

    cout<<vk%MOD<<"\n";

    return 0;
}