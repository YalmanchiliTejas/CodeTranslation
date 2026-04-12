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
#define   mod  998244353
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

int d[100005];

void devisor(int r,int n){
    for (int i=r;i<=n;i++){
        for (int j=i;j<=n;j+=i) 
            d[j]++;
    }
}

inline void solve(){
    int  n, k, ans = 0; 
    cin >> n >> k ;
    for (int b=1;b<=n;b++ ) {
        int m=(n+1)/b;
        ans += m*max(0LL,b-k); 
        if (k==0) ans--; 
        ans += max(0LL,(n+1)%b-k);
    } 
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
