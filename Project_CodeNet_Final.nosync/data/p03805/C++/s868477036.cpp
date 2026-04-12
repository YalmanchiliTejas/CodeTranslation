#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i < (int)(n);i++)
typedef long long ll;

vector<int> adj[10];

int main(){
  int cnt = 0;
  int n,m;
  cin >> n >> m;

  int i;
  int perm[10];
  rep(i,0,n) perm[i] = i + 1;

  int a,b;
  rep(i,0,m){
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  do{
    for(i = 0;i < n - 1;i++){
      int t = perm[i + 1];
      int k = adj[perm[i]].size();

      int j;
      int flag = 0;
      for(j = 0;j < k;j++){
        if(adj[perm[i]][j] == t) flag = 1;
      }

      if(flag == 0) break;

      if(i == n - 2) cnt++;
    }
  }while(next_permutation(perm + 1,perm + n));

  cout << cnt << endl;

  return 0;
}