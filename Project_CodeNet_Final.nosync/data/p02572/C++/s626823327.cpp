#include "bits/stdc++.h"

#define ll long long
#define ull unsigned long long
#define ld long double

#define tiii tuple < int, int, int >
#define pii pair < int, int >
#define pll pair < ll, ll >
#define pci pair < char, int >
#define psi pair < string, int >
#define pis pair < int, string >

#define vi vector < int >
#define vd vector < double >
#define vld vector < ld >
#define vll vector < ll >
#define vs vector < string >
#define vc vector < char >
#define vpi vector < pii >
#define vpll vector < pll >
#define vpis vector < pis >

#define pb push_back
#define mt make_tuple
#define gt0 get < 0 >
#define gt1 get < 1 >
#define gt2 get < 2 >

#define pi acos(-1)

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

ll a[maxn];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    fast;

    int n;

    cin >> n;

    ll sum = 0;

    for(int i = 0; i < n; i++) cin >> a[i], sum += a[i], sum %= mod;

    ll ans = 0;

    for(int i = 0; i < n; i++){
        sum -= a[i];

        if(sum < 0) sum += mod;

        ans += a[i] * sum;
        ans %= mod;
    }

    if(ans < 0) ans += mod;

    cout << ans << endl;

    return 0;
}
