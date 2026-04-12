#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  int n,m,k;
  cin >> n >> m >> k;
  vector<vector<int>> v(n,vector<int>(k));
  vector<int> d(m);
  vector<int> td(n,-1);
  rep(i,m){
    cin >> d[i];
    d[i]--;
    td[d[i]]=i;
  }
  rep(i,n){
    rep(j,k){
      cin >> v[i][j];
      v[i][j]--;
    }
  }
  vector<vector<int>> e(1<<m);
  vector<int> dp(1<<m,0);
  rep(j,k){
    dp[0]=0;
    e[0].push_back(0);
    repp(i,1,1<<m){
      rep(x,m){
        if(i&(1<<x)){
          if(td[v[d[x]][j]]!=-1) dp[i]=dp[i-(1<<x)]|(1<<td[v[d[x]][j]]);
          else dp[i]=dp[i-(1<<x)];
          break;
        }
      }
      e[i].push_back(dp[i]);
    }
  }
  vector<int> dist(1<<m,IINF);
  queue<int> q;
  q.push((1<<m)-1);
  dist[(1<<m)-1]=0;
  while(!q.empty()){
    int now = q.front();
    q.pop();
    rep(i,k){
      if(dist[e[now][i]]!=IINF) continue;
      dist[e[now][i]]=dist[now]+1;
      q.push(e[now][i]);
    }
  }
  cout << dist[0] << endl;
  return 0;
}

