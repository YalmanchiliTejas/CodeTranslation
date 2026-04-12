#include<bits/stdc++.h>
#define rep(i,f,n) for(int i=(f); (i) < (n); i++)
#define repe(i,f,n) for(int i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;

int main() {
  int n; cin >> n;
  int m; cin >> m;
  vector<int> path[m];
  rep(i, 0, m){
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    path[i].push_back(tmp1);
    path[i].push_back(tmp2);
  }

  vector<int> perm(n);
  rep(i, 0, n) perm[i] = i + 1;

  int ans = 0;
  do{

    if(perm[0] != 1) break;

    int goalcount = 0;
    rep(i, 0, n - 1){
      int from = perm[i];
      int to   = perm[i + 1];
      rep(j, 0, m){
        if((from == path[j][0] && to == path[j][1]) || (from == path[j][1] && to == path[j][0])){
          goalcount++;
          break;
        }
      }
    }
    if(goalcount == n -1) ans++;

  }while(next_permutation(perm.begin(), perm.end()));

  cout << ans << endl;
  
  return 0;
}