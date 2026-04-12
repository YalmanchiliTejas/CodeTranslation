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
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
using namespace std;

inline void solve(){ 
    int a,b,c,x,y,ans=0; 
    cin >> a >> b >> c >> x >> y ; 
    if (a+b>2*c){ 
        int f = min(x,y) ; 
        ans = f*2*c; 
        x -= f;y-=f; 
        if (x){ 
            if (c*2<=a) ans += x*c*2;
            else ans += x*a;
        }
        else {
            if (c*2 <= b) ans += c*2*y;
            else ans += y*b;
        }
    }
    else 
        ans = x*a+y*b;
    cout << ans << endl;
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
