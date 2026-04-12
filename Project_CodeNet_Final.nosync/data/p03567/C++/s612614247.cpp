#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define mod 1000000007
#define maxn 100005
#define IN freopen("nocross.in","r",stdin)
#define OUT freopen("nocross.out","w",stdout)
#define FOR(i,a,b) for(i=a ; i<=b ; i++)
#define ROF(i,a,b) for(i=a ; i>=b ; i--)
#define DBG pf("Hi\n")
#define INF 2000000000000000000LL
#define i64 long long int
#define eps (1e-8)
#define xx first
#define yy second
#define ln 17
// #define off 1000000
#define sq(x) ((x)*(x))

using namespace __gnu_pbds;
using namespace std ;

template <class T>  inline void smax(T &x,T y){ x = max((x), (y)); }
template <class T>  inline void smin(T &x,T y){ x = min((x), (y)); }

// typedef tree< i64, null_type, less<i64>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    string s ;

    cin>>s ;

    for(int i=s.size() - 1 ; i>=1 ; i--)
    {
        if(s[i]=='C' && s[i-1]=='A')
        {
            printf("Yes\n") ;
            return 0 ;
        }
    }
    printf("No\n") ;
    return 0 ;
}
