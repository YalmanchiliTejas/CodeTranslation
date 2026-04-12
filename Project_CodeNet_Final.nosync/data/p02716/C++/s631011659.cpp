#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 100000000
#define INF 1000000000000000000
#define MOD 1000000007
#define mod 1000000007
#define REP(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define REPE(i, a, n) for (ll i = a; i <= (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int,int>Pin;
typedef pair<ll,ll>Pll;
template<class T> using V=vector<T>;
long long GCD(long long a, long long b) {return b?GCD(b,a%b):a;}
long long LCM(long long a, long long b) {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
ll cmp(pair<ll,ll>a,pair<ll,ll> b){
        if(a.se!=b.se)
        return a.se<b.se;
        else
        return a.fi<b.fi;
}
//----------------------------------------------------------------------
ll dp[200020][3];
//----------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------  
    //ll begin_time=clock();
    //-------------------------------
    ll n;cin>>n;
    V<ll>a(n);
    for(ll i =0;i<n;i++){
        cin>>a[i];
    }
    ll ans=-INF;
    for(ll i=0;i<200020;i++){
        for(ll j=0;j<3;j++){
            dp[i][j]=-INF;
        }
    }
    if(n%2==0){
        dp[0][0]=a[0];
        dp[1][1]=a[1];
        for(ll i=2;i<n;i++){
            for(ll j=0;j<2;j++){
                chmax(dp[i][j],dp[i-2][j]+a[i]);
                if(j-1>=0 and i>=3){
                    chmax(dp[i][j],dp[i-3][j-1]+a[i]);
                }
            }
        }
        chmax(ans,dp[n-2][0]);
        chmax(ans,dp[n-1][1]);
    }
    else{
        dp[0][0]=a[0];
        dp[1][1]=a[1];
        dp[2][2]=a[2];

        for(ll i=2;i<n;i++){
            for(ll j=0;j<3;j++){
                chmax(dp[i][j],dp[i-2][j]+a[i]);
                if(j-1>=0&&i>=3){
                    chmax(dp[i][j],dp[i-3][j-1]+a[i]);
                }
                if(j-2>=0 and i>=4){
                    chmax(dp[i][j],dp[i-4][j-2]+a[i]);
                }
            }
        }
        chmax(ans,dp[n-3][0]);
        chmax(ans,dp[n-2][1]);
        chmax(ans,dp[n-1][2]);
    }
    cout<<ans<<endl;
    //-------------------------------  
    //ll end_time=clock();cout<<"time="<<end_time-begin_time<<"ms"<<endl;
    //-------------------------------
    return 0;
}
//----------------------------------------------------------------------


































