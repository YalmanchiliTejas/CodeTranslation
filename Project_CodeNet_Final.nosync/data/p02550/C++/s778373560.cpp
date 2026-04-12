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
#include <functional>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi   vector<int> 
#define   co(x)  cout << x << '\n' 
#define   dbg(x)  cerr << #x << " = " << x << '\n' 
#define   bitcount(x)  (int)__builtin_popcount(x) 
#define   sz(x)  (int)x.size()
#define   all(a) a.begin(),a.end() 
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

inline void solve(){
    map <int,int>  cnt, store ; 
    int  n, x, m, ans = 0 ; 
    cin >> n >> x >> m ; 
    int cur = x ; 
    ans = x ; 
    store[1] = x ; 
    for (int i=2;i<=n;i++){
        cur = (cur*cur%m) ; 
        if (cur) {
            if (cnt[cur]){
                int k = i-cnt[cur];
                int r = n-i+1;
                ans += r/k * ( store[i-1] - store[cnt[cur]-1] ) ; 
                r = r%k;
                ans += store[cnt[cur]+r-1] - store[cnt[cur]-1] ; 
                break;
            }
            else ans += cur; 
        }
        else break ; 
        cnt[cur] = i ; 
        store[i] = ans ; 
     }
    co ( ans ) ; 
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
