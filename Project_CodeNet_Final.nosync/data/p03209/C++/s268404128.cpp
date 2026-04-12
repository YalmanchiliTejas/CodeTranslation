#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M 1000000007
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
#define int ll

int n,x;
int a[1000];
int b[1000];

signed main(){
  cin>>n>>x;
  a[0] = 1;
  b[0] = 1;

  FOR(i,1,n+1){
    a[i] = a[i-1]*2 + 1;
    b[i] = b[i-1]*2+3;
  }

  int ans=0;
  while(n != -1){
    if(x==b[n]){
      ans+=a[n];
      x-=b[n];
    }
    else if(x>b[n]/2){
      ans+=a[n-1]+1;
      x-=b[n]/2 + 1;
    }
    else if(x==b[n]/2){
      ans+=a[n-1];
      x-=b[n]/2;
    }
    else {
      x--;
    }
    n--;
  }


  cout<<ans<<endl;
}