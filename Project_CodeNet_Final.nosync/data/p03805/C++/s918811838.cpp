#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> to(n+1,vector<int>(0,0));
  rep(i,m){
    int a,b;
    cin >> a >> b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<int> v(n);
  rep(i,n) v[i] = i+1;
  int ans = 0;
  do{
    if(v[0] != 1) continue;
  	bool fail_at_least_i = 0;
    rep(i,n-1){
      int now = v[i];
      int next = v[i+1];
      bool suc_at_least_j = 0;
      rep(j,to[now].size()){
        if(to[now][j] == next) suc_at_least_j = 1;
      }//j
      if(!suc_at_least_j) fail_at_least_i = 1;
    }//i
    if(!fail_at_least_i) ans ++;
  }while (next_permutation(v.begin(), v.end()));
  cout << ans << endl;
}