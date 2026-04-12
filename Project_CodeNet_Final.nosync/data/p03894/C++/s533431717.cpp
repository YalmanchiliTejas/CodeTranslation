#include<bits/stdc++.h>
#define watch(x) cout<<(#x)<<" is "<<(x)<<endl
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back
#define pq priority_queue
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define elif else if

using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using pll=pair<ll,ll>;
using pss=pair<string,string>;
using pdd=pair<ld,ld>;
using graph=vector<vector<int>>;
using wgraph=vector<vector<pll>>;

const ll MOD=1000000007;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int ex[8]={1,1,0,-1,-1,-1,0,1};
const int ey[8]={0,1,1,1,0,-1,-1,-1};
const ld E=1e-9;

template<class T> void chmin(T &a, T b){a=min(a, b);}
template<class T> void chmax(T &a, T b){a=max(a, b);}

ll abs1(ll a){if(a>=0)return a;else return -a;}
ll pow1(ll a,ll b,ll p=LLONG_MAX){
  ll ret=1;
  while(b!=0){
    if((b&1)==1)ret*=a;
    a*=a;
    if(a>=p)a%=p;if(ret>=p)ret%=p;
    b=b>>1;
  }
  return ret;
}
int digit(ll a,ll b=10){int i=0;while(a!=0){a/=b;i++;}return i;}
ll gcd1(ll a,ll b){
  if(a==0 || b==0)return 0;
  ll n;while(a%b!=0){n=a%b;a=b;b=n;}return b;
}
ll solveLinear(ll n,ll m,ll c){
  if(n==0 && m==0)return 0;
  ll a[100],b[100];a[0]=n;b[0]=m;int i=1;
  while(b[i-1]!=0){a[i]=b[i-1];b[i]=a[i-1]%b[i-1];i++;}
  n=i;if(c%a[n-1]!=0)return 0;
  ll x=c/a[n-1],y=0;
  for(i=1;i<n;i++){ll cnt=x;x=y;y=cnt-(a[n-i-1]/b[n-i-1])*y;}
  return x;
}
ll modRev(ll a,ll p=MOD){
  a%=p;ll n=solveLinear(a,p,1);
  n%=p;if(n<0)return n+p;
  return n;
}
ll fact(ll n,ll p=MOD){
  if(n<0)return 0;
  ll ret=1;
  for(int i=1;i<=n;i++){ret=ret*i;if(ret>=p)ret%=p;}
  return ret;
}
ll perm(ll n,ll k,ll p=MOD){
  if(n<0 || k<0 || n<k)return 0;
  ll ret=1;
  rep(i,k){ret=ret*(n-i);if(ret>=p)ret%=p;}
  return ret;
}
ll binom(ll n,ll k,ll p=MOD){
  return (perm(n,k,p)*modRev(fact(k)))%p;
}
int bis(vector<int> v,int key){
  int left=-1,right=v.size();
  while(abs1(right-left)>1){
    int mid=left+(right-left)/2;
    if(v[mid]<=key)left=mid;
    else right=mid;
  }
  return left;
}

int main(){
  int i,j,k,cnt=0;
  int n,q;
  cin>>n>>q;
  int a[q],b[q];
  rep(i,q){
    cin>>a[i]>>b[i];
    a[i]--;b[i]--;
  }
  set<int> s;
  s.insert(0);
  s.insert(1);
  int c[n];
  rep(i,n)c[i]=i;
  rep(i,q){
    swap(c[a[i]],c[b[i]]);
    if(c[a[i]]==0)cnt=a[i];
    if(c[b[i]]==0)cnt=b[i];
    if(cnt>1)s.insert(c[cnt-1]);
    if(cnt<n-1)s.insert(c[cnt+1]);
  }
  cout<<s.size()<<endl;
}
