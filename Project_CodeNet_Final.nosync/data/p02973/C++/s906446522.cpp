
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
#define vi vector<int>


signed main(){

 int n;
  cin>>n;
  vector<int> a(n);
  bool flag=true;
  rep(i,n){
    cin>>a[i];
    if(a[0]!=a[i]) flag=false;
  }

  if(flag){
    cout<<n<<endl;
    return 0;
  }

  vector<int> b(n+1,inf);

  rrep(i,n-1){
    int t=upper_bound(all(b),a[i])-b.begin();
    b[t]=a[i];
  }

  cout<<(lower_bound(all(b),inf)-b.begin())<<endl;

}