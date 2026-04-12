/*
                       _oo0oo_
                      o8888888o
                      88" . "88
                      (| -_- |)
                      0\  =  /0
                    ___/`---'\___
                  .' \\|     |// '.
                 / \\|||  :  |||// \
                / _||||| -:- |||||- \
               |   | \\\  -  /// |   |
               | \_|  ''\---/''  |_/ |
               \  .-\__  '-'  ___/-. /
             ___'. .'  /--.--\  `. .'___
          ."" '<  `.___\_<|>_/___.' >' "".
         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
         \  \ `_.   \_ __\ /__ _/   .-` /  /
     =====`-.____`.___ \_____/___.-`___.-'=====
                       `=---='
 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
  Vikash Kumar @ Codechef/codeforces 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/   
#include<bits/stdc++.h>
 
#define ll                    long long int
#define ll_MAX                LLONG_MAX
#define ll_MIN                LLONG_MIN
#define pi                    3.14159265358979323846
#define count_1(n)            __builtin_popcountll(n)
#define MOD                   1000000007
#define MAX                   1e9
#define MIN                   -1e9
#define itoc(c)               ((char)(((int)'0')+c))
#define mid(s,e)              (s+(e-s)/2)
const int MX=10010896;
const int lmt=3164;
const int N=10000001;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}

const ll MXX=3005;
ll dp[MXX][MXX];

inline void solve(){
    /*_Start_*/
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
      cin>>a[i];
    for(ll l=0;l<n;l++){
      for(ll r=l;r>=0;r--){
        if(l==r)
          dp[l][r]=a[l];
        else
          dp[l][r]=max( a[l]-dp[l-1][r],a[r]-dp[l][r+1] );
      }
    }
    cout<<dp[n-1][0]<<endl;
    /*_End_*/
   
}

int main()
{
	cout<<fixed<<setprecision(12);
	//freopen("input.txt", "r", stdin);
	fastio;ll  t=1,tc=1;
	//cin>>t;
	while(t--){solve();}return 0;
}