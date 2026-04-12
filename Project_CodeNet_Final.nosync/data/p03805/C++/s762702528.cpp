#include <bits/stdc++.h>
using namespace std;
using Graph= vector<vector<int>>;

int N,M;
Graph(G);
int ans=0;

void input(){
  cin >> N >> M;
  G.resize(N,vector<int>(N));
  int a,b;
  for(int i=0;i<M;i++){
    cin >> a >> b;
    G[a-1][b-1]=G[b-1][a-1]=1;
  }
}


void solve(){
  vector<int> order(N);
  for(int i=0;i<N;i++){
    order[i]=i;
  }
  do {
    int temp=0;
    for(int i=1;i<N;i++){
      temp+=G[order[i-1]][order[i]];
    }
    if(temp==N-1){
      ans+=1;
    }
  } while (next_permutation(order.begin()+1,order.end()));
}

int main(){
  input();
  solve();
  cout << ans << endl;
  return 0;
}
