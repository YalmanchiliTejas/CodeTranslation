#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
using vs = vector<string> ;
#define all(v) v.begin(),v.end()

#define MAX_V 10
#define INF 1e9

struct edge { int to;int cost;};

vector<edge> G[MAX_V];
using P = pair<int, int>;
int V,ans;

int bfs(int v){
  ll ans=0;
  deque<vector<int>> qv;
  vector<int> d;d.push_back(v);
  qv.push_back(d);
  while(!qv.empty()){
    vector<int> d_tmp = qv.back();
    qv.pop_back();
    int nowv = d_tmp[d_tmp.size()-1];
    //ここで別々のd_tmpにしないと
    for(int i=0;i<G[nowv].size();++i){
      if(find(all(d_tmp),G[nowv][i].to)==d_tmp.end()){
        d_tmp.push_back(G[nowv][i].to);
        if(d_tmp.size()==V) ans++;
        else{
          qv.push_back(d_tmp);
          d_tmp.erase(d_tmp.end()-1);
        }
        //rep(h,d_tmp.size()) cout<<d_tmp[h];
      }
    }
    //cout<<endl;
  }
  return ans;
}


int main(){
  cin >> V;
  int E;cin>>E;
  rep(i,E){
    int a,b;cin>>a>>b;a--,b--;
    edge e1={a, 1},e2={b, 1};
    G[a].push_back(e2);
    G[b].push_back(e1);
  }
  cout << bfs(0) << endl;
}