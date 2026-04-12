#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<int>>;
Graph G(10);

int N,M;
ll ans = 0;

void dfs(int n,int x,bitset<10> s){
  s.set(x);
  if(n == N){
    for(int i = 0;i < N;i++){
      if(!s.test(i)){
        return ;
      }
    }
    ans++;
    return ;
  }
  int m = G[x].size();
  for(int i = 0;i < m;i++){
    if(!s.test(G[x][i])){
      dfs(n+1,G[x][i],s);
    }
  }
}

int main(){
  cin >> N >> M;
  for(int i = 0;i < M;i++){
    int a,b;cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1,0,0);
  cout << ans << endl;
}