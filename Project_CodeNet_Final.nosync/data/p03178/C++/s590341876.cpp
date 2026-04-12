#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define sync()      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fileIO()    freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout)
#define F           first
#define S           second
#define ers         erase
#define ins         insert
#define db          pop_back
#define pb          push_back
#define df          pop_front
#define pf          push_front
#define SZ(x)       ((ll)x.size())
#define sqr(x)      (x)*(x)
#define Blz(x)      __builtin_clz(x)
#define Brz(x)      __builtin_ctz(x)
#define Bones(x)    __builtin_popcount(x)
#define all(x)      x.begin(),x.end()
#define kill(x)     return cout<<x,0
#define dbgp(x)     cerr<< #x << " = " << x.F << ", " << x.S << endl
#define dbg(x)      cerr<< #x << " = " << x << endl
#define ddbg(i,x)   cerr<< #i << " = " << i << " / "; dbg(x[i])
#define tdbg(i,E,x) cerr<< #i << " = " << i << " / "; ddbg(E,x[i])
typedef long long                                 ll;
typedef long double                               ld;
typedef unsigned short int                        usi;
typedef pair<long long,bool>                      plb;
typedef pair<long long,long long>                 pll;
typedef string                                    str;
typedef priority_queue<ll>                        maxheap;
typedef priority_queue<ll,vector<ll>,greater<ll>> minheap;
typedef priority_queue<pll,vector<pll>,greater<pll>> djq;
const ll maxn=1e5+12, inf=4e18, mod=1e9+7; const ld pi=3.14159265359, eps=1e-9;
ll dp[10010][2][110];
int main(){
    sync();
    string k; int d; cin>>k>>d;
    int len=SZ(k),x;
    dp[0][1][0]=1;
    for(int i=0;i<len;i++)for(bool j:{0,1}){
        for(int l=0;l<d;l++){
            if(!dp[i][j][l]) continue;
            if(!j) for(int m=0;m<10;m++) dp[i+1][0][(l+m)%d]+=dp[i][j][l], dp[i+1][0][(l+m)%d]%=mod;
            else{
                x=k[i]-'0';
                for(int m=0;m<x;m++) dp[i+1][0][(l+m)%d]+=dp[i][j][l], dp[i+1][0][(l+m)%d]%=mod;
                dp[i+1][1][(l+x)%d]+=dp[i][j][l], dp[i+1][1][(l+x)%d]%=mod;
            }
            //dbg(dp[i][j][l]);
        }
    }
    cout<<(dp[len][0][0]+dp[len][1][0]-1+mod)%mod;
    return 0;
}
/**
 (                            )   (   )
 )\ )             (      )  ( /(  () /(
(()/(  (  (    (  )\  ( /(  )\()) )\ ())
 /(_))_)  )\   )\((_) )(_))(_)\) ((_)(_)
(_)) __| ((_) ((_)| |((_)_)| |(_)| |_| |
  | (_ |/ _ \/ _ \| |/ _` || / / |  _  |
   \___|\___/\___/|_|\__,_||_\_\ |_| |_|
**/
