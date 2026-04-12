
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



int n;
vector<int> v;
int ans=0;

void f(int c){
  int res=0;
  bool flag[200000]={};


  for(int kc=c;kc<n-1;kc+=c){
    int a=n-1-kc;
    int b=a-c;
    if(a<=b||b<=0) break;
    if(a==kc||flag[a]||flag[kc]) break;
    res+=v[a]+v[kc];
    flag[a]=true;
    flag[kc]=true;
    ans=max(ans,res);
  }
}




main(){
  cin>>n;
  v.resize(n);
  
  rep(i,n){
    cin>>v[i];
  }

  for(int i=1;i<n-1;i++){
    f(i);
  }

  cout<<ans<<endl;
}
