#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cin.tie(0)
#define int int64_t
#define ii pair<int, int>
#define endl '\n'
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define F first
#define S second
#define pb push_back
#define FOR(i,l,r) for(int i=l; i<r; ++i)
#define ROF(i,r,l) for(int i=r; i>l; --i)
#define all(x) x.begin(), x.end()
#define amin(a,b) a = min(a,b)
#define amax(a,b) a = max(a,b)
#define test int t; cin >> t; while(t--) solve();

using namespace std;
typedef long long ll;

const int MAXN = 2000005;
const int MAXINT = 2147483098;
const int MAXLL = 9223372036854775258LL;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;



int pref[MAXN];



int32_t main()
{
    //freopen("holiday.in", "r", stdin);
    fast;
    //test;

   int n;
   cin >> n;
   vi a(n);
   cin >> a[0];
   pref[0] = a[0];
   FOR(i,1,n) cin >> a[i], pref[i] = (pref[i-1]+a[i])%MOD;
   int ans = 0;
   FOR(i,0,n){
        ans  = (ans+(a[i]*(pref[n-1]-pref[i]+MOD))%MOD)%MOD;
   }
   cout << ans;


   return 0;
}
