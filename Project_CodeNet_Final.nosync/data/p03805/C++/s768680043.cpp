#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool G[10][10]; //隣接行列

int main(){
  ll N,M,i,a,b;
  ll res = 0;
  cin >> N >> M;
  for(i=0;i<=M-1;i++){
    cin >> a >> b;
    a--;
    b--;
    G[a][b] = true;
    G[b][a] = true;
  }
  ll ord[N];
  
  for(i=0;i<=N-1;i++)
    ord[i] = i;
    
  do{
    if(ord[0] != 0) break;
    bool x = true;
    for(i=0;i<=N-2;i++){
      ll from = ord[i];
      ll to = ord[i+1];
      if(!G[from][to]) x = false;
    }
    if(x) res++;
    next_permutation(ord,ord+N);
  }while(true);

  cout << res << endl;
}