#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int n,m;
vector<int> v[10];
ll ans;
vector<bool> used;

void dfs(int now,vector<bool>& c,int times){
  if(times==n-1){
    rep(i,c.size()){
      if(!c[i] && i!=now)return;
    }
    ans++;
    return;
  }
  vector<bool> temp;
  rep(i,c.size())temp.push_back(c[i]);
  temp[now]=true;
  rep(i,v[now].size()){
    if(!temp[v[now][i]])dfs(v[now][i],temp,times+1);
  }
  return;
}

int main(){
  cin >> n >> m;
  rep(i,m){
    int x,y;
    cin >> x >> y;
    x--,y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  rep(i,n)used.push_back(false);
  used[0]=true;
  dfs(0,used,0);
  cout << ans << endl;
return 0;}