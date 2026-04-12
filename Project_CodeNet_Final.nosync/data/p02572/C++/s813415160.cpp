/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  1000000007
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){
    int n; cin>>n;
    vi a(n+1),pref(n+1);
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    pref[n] = a[n];
    for (int i=n-1;i>0;i--){
      pref[i] = pref[i+1]+a[i];
      pref[i] = pref[i]%mod;
    } 
    int ans=0;
    for (int i=1;i<=n-1;i++){
        ans += (a[i]*pref[i+1])%mod;
        ans = ans % mod;
    }
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
