#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {

  int N,M;
  cin >> N >> M;

  vector<vector<bool>> G(N,vector<bool>(N,false));
  vector<int> num(N,false);

  for(int i = 0;i < M;i++) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    G[a][b] = true;
    G[b][a] = true;
  }

  for(int i = 0;i < N;i++) {
    num.at(i) = i;
  }

  int res = 0;
  do {
    if(num.at(0) != 0) break;
    bool ok = true;
    for(int i = 0;i < N-1;i++) {
      int from = num.at(i),to = num.at(i+1);
      if(!G.at(from).at(to)) ok = false;
    }

    if(ok) res++;

  }while(next_permutation(num.begin(),num.end()));

  cout << res << endl;
}

