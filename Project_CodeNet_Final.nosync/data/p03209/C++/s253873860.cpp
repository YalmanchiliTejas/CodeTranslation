#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<int,int>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll b[51],p[51];
ll make(ll n,ll x){
   if(x==1)return (n?0:1);
   if(n==0)return 0;
   if(x<=1+b[n-1])return make(n-1,x-1);
   if(x==2+b[n-1])return p[n-1]+1;
   if(x<=b[n-1]*2+2)return p[n-1]+1+make(n-1,x-b[n-1]-2);
   return 2*p[n-1]+1;
}
int main(){
  ll n,x;
  cin>>n>>x;
  b[0]=1;p[0]=1;
  for(int i=0;i<n;i++){
      b[i+1]=b[i]*2+3;
      p[i+1]=p[i]*2+1;
  }
  cout<<make(n,x)<<endl;
}