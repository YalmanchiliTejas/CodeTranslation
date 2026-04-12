#include<bits/stdc++.h>

using namespace std;
typedef  long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

template<class T> ll llpow(T x,T n){ll ans=1;if(x==0)ans=0;while(n){if(n&1)ans*=x;x*=x;n>>=1;}return ans;}
template<class T> inline T gcd(T x,T y){if(y==0)return x; else {return gcd(y,x%y);}}
template<class T> inline T lcm(T x,T y){return x/gcd(x,y)*y;}

#define rep(i,n) for(ll i=0;i<(ll)n;i++)
#define rep2(i, begin_i, end_i) for (ll i = (ll)begin_i; i < (ll)end_i; i++)
int dp[105][4][2];
long long INF = 1LL<<60;
int main(){
    string s;
    int k;
    cin>>s>>k;
    int n=s.size();
    dp[0][0][0]=1;
    rep(i,n)rep(j,4)rep(l,2){
        int d=s[i]-'0';
        rep(nd,10){
            int ni=i+1,nj=j,nl=l;
            if(nd!=0)nj++;
            if(nj>k)continue;
            if(nl==0){
                if(d<nd)continue;
                else if(d>nd)nl=1;
            }
            dp[ni][nj][nl]+=dp[i][j][l];
        }
    }
    int ans=dp[n][k][0]+dp[n][k][1];
    cout<<ans<<endl;
    return 0;
}


