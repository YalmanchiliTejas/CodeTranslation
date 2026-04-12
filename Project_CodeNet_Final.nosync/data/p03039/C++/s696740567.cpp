
#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
#define IN(a,n) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}




ll power(ll x,ll k){
  ll ret=1;
  while(k>0){
    if(k&1) (ret*=x) %= M;
    (x*=x) %= M;
    k >>= 1;
  }
  return ret;
}

int inverse(int a){
  return power(a,M-2);
}


int comb(int n,int k){
  int res=1;
  rep(i,k){
    res*=n-i;
    res%=M;
    res*=inverse(i+1);
    res%=M;
  }
  return res;
}



main(){
  int n,m,k;
  cin>>n>>m>>k;
  int t=comb(n*m-2,k-2);

  int ans=0;
  rep(i,n){
    int s=((((((n-1-i)*(n-i)/2)%M)*m)%M)*m)%M;
    ans+=s;
    ans%=M;
  }

  rep(i,m){
    int s=((((((m-1-i)*(m-i)/2)%M)*n)%M)*n)%M;
    ans+=s;
    ans%=M;
  }

  cout<<(ans*t)%M<<endl;
}
