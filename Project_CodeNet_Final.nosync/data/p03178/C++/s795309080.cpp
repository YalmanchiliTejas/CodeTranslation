#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define pb push_back
//#all(x) (x).begin(),(x).end()

//int const N = 1;
int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b)
{
    if(b==0)
        return 1 % MOD;
    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    if(b%2)
        x = (x * a) % MOD;
    return x;
}

int const N = 1e4 + 10;//;
ll dp[N][110][3];
string s;
ll d;
//ll mara[N] ;

ll F(int pos,int mod,bool isbig)
{
    if(pos >= s.size() )
        return mod == 0;
    ll &r = dp[pos][mod][isbig] ;

    if(r != -1) return r;

    r = 0;
    if(isbig)
    {
        for(int i = 0; i <= 9; i++)
        {
            r += F(pos+1, (mod +  i) % d, isbig);
            r %= MOD;
        }

    }
    else{
        for(int i = 0; i <= (s[pos] - '0'); i++)
        {
            if( (s[pos] - '0') == i) {
                r += F(pos+1, (mod + i) % d, isbig) ;
                r %= MOD;
            }
            else{
                r += F(pos+1,(mod +  i) % d, 1);
                r %= MOD;
            }

        }
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> s >> d;
    //mara[0] = 1 % d;

//    for(int i = 1; i < N ; i++)
//        mara[i] = (mara[i-1] * 10) % d;

    cout <<  (F(0,0,0) - 1 + MOD ) % MOD << endl;
    //for(int i = 1; i <= )
    return 0;
}


