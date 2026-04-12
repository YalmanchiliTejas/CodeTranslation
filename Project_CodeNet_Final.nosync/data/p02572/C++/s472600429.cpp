#include <bits/stdc++.h>
#define sp putchar(' ')
#define en putchar('\n')
#define MOD(x) ((((x)%Mod)+Mod)%Mod)
const int MAXN = 500005 ;
using namespace std ;
int64_t s[MAXN],a[MAXN] ;
int64_t Mod = 1000000007 ;
int n ;
int main()
{
    ios::sync_with_stdio(false) ;
    while(cin >> n) {

        for(int i = 1;i <= n; ++ i) {
            int64_t buff ;
            cin >> a[i] ;
        }
        s[0] = 0 ;
        int64_t ans = 0 ;
        for(int i = 1;i <= n;++i) {
            s[i] = MOD(s[i - 1] + a[i]) ;
            ans = MOD(ans + MOD(s[i - 1] * a[i])) ;
        }
        cout << ans << endl ;
    }
}
