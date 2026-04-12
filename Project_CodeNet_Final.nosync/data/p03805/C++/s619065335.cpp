#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  vector<vector<bool>> g(n,vector<bool>(n,false));
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--,b--;
    g[a][b]=true;
    g[b][a]=true;
  }
  vector<int> a;
  FOR(i,1,n) a.push_back(i);
  int ans=0;
  do{
    bool flag=true;
    int now=0;
    rep(i,a.size()){
      if(!g[now][a[i]]){
        flag=false;
        break;
      }
      now=a[i];
    }
    if(flag) ans++;
  }while(next_permutation(begin(a),end(a)));
  cout<<ans<<endl;
}