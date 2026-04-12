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
vector<int>kaijo;
void init_fact(int n){
    kaijo.resize(n+1);
    kaijo[0]=1;
    for(int i=1;i<=n;i++){
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
    //if(!kaijo[0])init_fact();
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
int n,x[200010],y[200010],MIN=INF,MAX=-INF,ans=INF;
signed main(){
    cin>>n;
    rep(i,n){
        cin>>x[i]>>y[i];
        chmin(MIN,x[i]);
        chmin(MIN,y[i]);
        chmax(MAX,x[i]);
        chmax(MAX,y[i]);
    }
    {
        int Rmi=INF,Rma=-INF,Bmi=INF,Bma=-INF;
        rep(i,n){
            int r=x[i],b=y[i];
            if(r>b)swap(r,b);
            chmin(Rmi,r);
            chmax(Rma,r);
            chmin(Bmi,b);
            chmax(Bma,b);
        }
        chmin(ans,(Rma-Rmi)*(Bma-Bmi));
    }
    {
        //(MAX-MIN)
        int ma=-INF;
        priority_queue<P,vector<P>,greater<P>>q;
        rep(i,n){
            int r=x[i],b=y[i];
            if(r>b)swap(r,b);
            q.push({r,b});
            chmax(ma,r);
        }
        chmin(ans,(MAX-MIN)*(ma-q.top().fi));
        rep(i,n){
            P p=q.top();
            q.pop();
            swap(p.fi,p.se);
            q.push(p);
            chmax(ma,p.fi);
            chmin(ans,(MAX-MIN)*(ma-q.top().fi));
        }
    }
    cout<<ans<<endl;
    return 0;
}
