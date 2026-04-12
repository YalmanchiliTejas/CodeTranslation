#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ff               first
#define ss               second
#define pb               push_back
#define all(x)           (x).begin(), (x).end()
#define mem0(x)          memset(x, 0, sizeof (x))
#define mem1(x)          memset(x, -1, sizeof (x))

typedef long long ll;
typedef vector <int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector <ii> vii;
typedef vector<vii> vvii;
typedef vector <ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

ll const MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> n;
    ll sum = 0;
    ll ans = 0;
    vll A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        sum += A[i];
    }
    for (int j = 0; j < n; ++j) {
        ans += A[j]*((sum - A[j])%MOD)%MOD;
        sum -= A[j];
    }
    cout << ans%MOD << "\n";
}