#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
string s;

ll dp[2][2][10001][102];
ll lim , tt , k , n , m;
vector < ll > inp ;

ll DP( ll pos , ll isSmall ,ll isStart, ll mod)
{
    if( pos == lim )
    {
        if(mod == 0 ) return 1;
        else return 0;
    }
    ll &ret = dp[isSmall][isStart][pos][mod];
    if(ret!=-1) return ret ;
    ll ses = isSmall ? 9 : inp[pos];
    ll i ;
    ret = 0 ;
  //  cout<<ret<<endl;
    if( !isStart )
    for ( i = 0 ; i <= ses ; i++ )
    {
        ret += DP( pos + 1 , isSmall | i < inp[pos] ,0, (i + mod)%k);
        ret %= 1000000007;
    }
    else
    {
         for ( i = 1 ; i <= ses ; i++ )
    {
        ret += DP( pos + 1 , isSmall | i < inp[pos] ,0, (i + mod)%k);
        ret %= 1000000007;
    }
    ret += DP( pos + 1 , 1 ,1, 0);
    ret %= 1000000007;
    }
    return ret%1000000007 ;
}

ll Cal()
{
    ll sz = s.size();
    for(ll i=0;i<sz;i++)
    {
        inp.pb(s[i]-'0');
    }
    lim = sz;
    return ((DP( 0 , 0 , 1 , 0 )+1000000007-1)%1000000007);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>s>>k;
    ll ans = Cal();
    cout<<ans<<endl;
    return 0;
}
