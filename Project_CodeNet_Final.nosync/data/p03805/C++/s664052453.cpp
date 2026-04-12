#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
typedef long long ll;
using namespace std;
const int MOD = 1000000007;
const int INF = 1010000000;
const double EPS = 1e-10;
const array<pair<int,int>,4> fd{make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

int main(){
  int n,m;cin>>n>>m;
  int num[] = {0, 1, 2, 3, 4, 5, 6, 7};
  bool c[8][8];rep(i,8)rep(j,8)c[i][j] = false;
  rep(i,m){
    int a,b;cin>>a>>b;a--;b--;
    c[a][b] = c[b][a] = true;
  }
  int ans = 0;
  do{
    bool b = true;;
    rep(i,n-1){
      if(!c[num[i]][num[i+1]]){
        b = false;break;
      }
    }
    if(b)ans++;
  }while(next_permutation(num+1, num+n));
  cout << ans << endl;
}
