#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
template<class T>void chmax(T &a,T b){if(a<b)a=b;}
template<class T>void chmin(T &a,T b){if(a>b)a=b;}
constexpr int INF=1000000000000000000;
constexpr int mod=1000000007;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int kaijo[200010];
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
void init_fact(){
    kaijo[0]=1;
    for(int i=1;i<=200000;i++){
        kaijo[i]=kaijo[i-1]*i;
        kaijo[i]%=mod;
    }
}
int modpow(int a,int b){
    if(b==0)return 1;
    if(b%2)return modpow(a,b-1)*a%mod;
    int memo=modpow(a,b/2);
    return memo*memo%mod;
}
int comb(int a,int b){
    if(!kaijo[0])init_fact();
    return kaijo[a]*modpow(kaijo[a-b],mod-2)%mod*modpow(kaijo[b],mod-2)%mod;
}
int inv(int x){
    x=modpow(x,mod-2);
    return x;
}
bool kosa(double ax,double ay,double bx,double by,double cx,double cy,double dx,double dy){
    double ta=(cx-dx)*(ay-cy)+(cy-dy)*(cx-ax);
    double tb=(cx-dx)*(by-cy)+(cy-dy)*(cx-bx);
    double tc=(ax-bx)*(cy-ay)+(ay-by)*(ax-cx);
    double td=(ax-bx)*(dy-ay)+(ay-by)*(ax-dx);
    return tc*td<0&&ta*tb<0;
}
int n;
int a[200010];
int dp[200010][3];
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,n)cin>>a[i];
    if(n%2==0){
        rep(i,n){
            rep(j,2){
                dp[i][j]=-INF;
            }
        }
        dp[0][0]=a[0];
        dp[1][1]=a[1];
        dp[2][0]=a[0]+a[2];
        for(int i=3;i<n;i++){
            rep(j,2){
                if(j>=0){
                    chmax(dp[i][j],dp[i-2][j]+a[i]);
                }
                if(j>=1){
                    chmax(dp[i][j],dp[i-3][j-1]+a[i]);
                }
            }
        }
        int ans=-INF;
        rep(j,2){
            chmax(ans,dp[n-1][j]);
            chmax(ans,dp[n-2][j]);
        }
        cout<<ans<<endl;
    }
    else{
        rep(i,n){
            rep(j,3){
                dp[i][j]=-INF;
            }
        }
        if(n==3){
            cout<<max({a[0],a[1],a[2]})<<endl;
            return 0;
        }
        dp[0][0]=a[0];
        dp[1][1]=a[1];
        dp[2][2]=a[2];
        dp[2][0]=a[0]+a[2];
        dp[3][1]=max(a[0]+a[3],a[1]+a[3]);
        for(int i=4;i<n;i++){
            rep(j,3){
                if(j>=0){
                    chmax(dp[i][j],dp[i-2][j]+a[i]);
                }
                if(j>=1){
                    chmax(dp[i][j],dp[i-3][j-1]+a[i]);
                }
                if(j>=2){
                    chmax(dp[i][j],dp[i-4][j-2]+a[i]);
                }
            }
        }
        int ans=-INF;
        rep(j,3){
            chmax(ans,dp[n-1][j]);
        }
        cout<<ans<<endl;
    }
	return 0;
}
