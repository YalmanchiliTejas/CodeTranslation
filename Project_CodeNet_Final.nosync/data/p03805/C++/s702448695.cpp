#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 1010101010101010;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(){
  int n,m; cin>>n>>m;
  Graph g(n);
  rep(i,m){
    int a,b; cin>>a>>b; a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ll count=0;
  vi x(n); rep(i,n) x[i]=i;
  do{
    bool m_judge=true;
    rep(i,n-1){
      bool judge=false;
      for(auto y :g[x[i]]){
        if(y==x[i+1]) judge=true;
      }
      if(!judge){
        m_judge=false;
        break;
      }
    }
    if(m_judge) count++;
  }while(next_permutation(x.begin()+1,x.end()));
  cout<<count;
}
