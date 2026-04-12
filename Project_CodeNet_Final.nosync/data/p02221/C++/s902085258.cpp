#include<bits/stdc++.h>
//ios::sync_with_stdio(false);
//cin.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pii,int> ppii;
typedef pair<int,pii> pipi;
typedef pair<ll,ll> pll;
typedef pair<pll,ll> ppll;
typedef pair<ll,pll> plpl;
typedef tuple<ll,ll,ll> tl;
ll mod=1000000007;
ll mod2=998244353;
ll inf=1000000000000000000;
double pi=2*acos(0);
#define rep(i,m,n) for(int i=m;i<n;i++)
#define rrep(i,n,m) for(int i=n;i>=m;i--)
int dh[4]={1,-1,0,0};
int dw[4]={0,0,1,-1};
int ddh[8]={-1,-1,-1,0,0,1,1,1};
int ddw[8]={-1,0,1,-1,1,-1,0,1};
ll lmax(ll a,ll b){
    if(a<b)return b;
    else return a;
}
ll lmin(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll Pow(ll n,ll k){
    ll ret=1;
    ll now=n;
    while(k>0){
        if(k&1)ret*=now;
        now*=now;
        k/=2;
    }
    return ret;
}
vector<deque<int>> dq[17];
string s;
int f(deque<int> dq2,int n){
    
    if(dq2.size()==1)return dq2[0];
  dq[n].push_back(dq2);
    deque<int> ret;
    for(int i=0;i<dq2.size();i+=2){
        if(s[abs(dq2[i]-dq2[i+1])-1]=='1')ret.push_back(max(dq2[i+1],dq2[i]));
        else ret.push_back(min(dq2[i],dq2[i+1]));
    }
    return f(ret,n+1);
}
int main(){
    int n;cin>>n;
    cin>>s;
    int p[1<<n];
    rep(i,0,1<<n){
        cin>>p[i];
        p[i]--;
    }
    deque<int> d;
    rep(i,0,1<<n)d.push_back(p[i]);
    int now=0;
    int c=2;
    int ans[1<<(n-1)];
    ans[0]=f(d,0)+1;
    int y=d.front();d.pop_front();
    d.push_back(y);
    ans[1]=f(d,0)+1;
    rep(i,2,1<<(n-1)){
        if(i==c){
            dq[now].clear();
            c*=2;
            now++;
        }
        deque<int> nd=dq[now][i-c/2];
      int yy=nd.front();nd.pop_front();
      nd.push_back(yy);
        ans[i]=f(nd,now)+1;
    }
rep(i,0,2){
    rep(j,0,1<<(n-1))cout<<ans[j]<<endl;
    
}
}
