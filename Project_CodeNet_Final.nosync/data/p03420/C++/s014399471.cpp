#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <stack>
#include <vector>
#define INF 0x3f3f3f3f
#define MOD 1000000009
# define FOR(i,a,n) for(register int i=a; i<=n; ++i)
# define FDR(i,a,n) for(register int i=a; i>=n; --i)
typedef long long ll;
typedef unsigned long long ull;

inline int scan() {
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}
inline void Out(int a) {
    if(a<0) {putchar('-'); a=-a;}
    if(a>=10) Out(a/10);
    putchar(a%10+'0');
}
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll cha = n-k;
    ll ans = (1+cha)*cha/2;

//    cout << ans << endl;
    ll ji = 1;
    ll ij = 1;
    for(ll i = cha; i >= 1; i--)
    {
//        if(ji <= k)
//        {
            ll kk = i/(k+ij)*ij;
            if((i%(k+ij))-k > 0)kk += (i%(k+ij))-k;
//            cout << kk << endl;
            ans += kk;
            ij++;
//            if(i%k == )
//        }
//        ji++;
    }
    if(k == 0)ans -= n;
    cout << ans << endl;
    return 0;
}
/*
                 ___====-_  _-====___
           _--^^^#####//      \\#####^^^--_
        _-^##########// (    ) \\##########^-_
       -############//  |\^^/|  \\############-
     _/############//   (@::@)   \\############\_
    /#############((     \\//     ))#############\
   -###############\\    (oo)    //###############-
  -#################\\  / VV \  //#################-
 -###################\\/      \//###################-
_#/|##########/\######(   /\   )######/\##########|\#_
|/ |#/\#/\#/\/  \#/\##\  |  |  /##/\#/  \/\#/\#/\#| \|
`  |/  V  V  `   V  \#\| |  | |/#/  V   '  V  V  \|  '
   `   `  `      `   / | |  | | \   '      '  '   '
                    (  | |  | |  )
                   __\ | |  | | /__
                  (vvv(VVV)(VVV)vvv)
                  ÁúÉñ±£ÓÓ ÓÀÎÞbug
*/
