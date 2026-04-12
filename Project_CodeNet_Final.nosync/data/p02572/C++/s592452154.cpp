#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define st first
#define sc second
#define arr array
#define yes cout << "Yes" <<"\n"
#define no cout << "No" <<"\n"
#define lb lower_bound
#define ub upper_bound
#define fast ios_base::sync_with_stdio(false)
#define out cin.tie(nullptr)
#define task "A"
#define open(task)  if(fopen(task".inp", "r")){freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define open_to_check(task)  if(fopen(task".inp", "r")){freopen(task".inp", "r", stdin);}
#define int64 long long

const int maxn = 3e5 + 2;
const int maxN = 1e5 + 5;
const ll mod = 1e9 + 7;

using namespace std;

/// Count : 1

ll a[maxn];


int main()
{
    //if(fopen(task".inp", "r")){
        //freopen(task".inp", "r", stdin);
        //freopen(task".out", "w", stdout);
    //}
    int n;
    cin >> n;
    ll sum = 0;
    ll ans = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        ans += (sum * a[i])%mod;
        ans %= mod;
        sum += a[i];
        sum %= mod;
    }
    cout << ans;
}
