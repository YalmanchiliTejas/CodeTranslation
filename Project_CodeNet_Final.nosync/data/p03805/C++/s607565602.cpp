#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  int N,M;
  cin>>N>>M;
  vector<map<int,bool>> g(N);
  for(int i = 0; i < M; i++){
    int x,y;
    cin>>x>>y;
    g[x-1][y-1]=true;
    g[y-1][x-1]=true;
  }
  vector<int> v(N-1);
  for(int i = 0; i < N-1; i++) v[i]=i+1;
  int ans = 0;
  do{
    for(int i = 0; i < N-1; i++){
      if(i==0){
        if(!g[0][v[i]]) break;
      }
      else {
        if(!g[v[i-1]][v[i]])break;
      }
      if(i==N-2) ans++;
    }
  }while(next_permutation(v.begin(),v.end()));
  cout<<ans<<endl;
}