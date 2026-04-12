#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
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
#define IN(n,a) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

vector<int> v[1000];
int n,m;
int ans;

void search(int k,int s,int b[]){
  if(s==n){
    ans++;
    return;
  }
  
  rep(i,v[k].size()){
    if(b[v[k][i]]) continue;
    b[v[k][i]]++;
    search(v[k][i],s+1,b);
    b[v[k][i]]--;
  }

}

int main(){
  cin>>n>>m;
  rep(i,m){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  int b[10]={};
  b[1]=1;
  search(1,1,b);

  cout<<ans<<endl;
}