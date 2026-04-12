#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define SUM(a)  accumulate((a).begin(),(a).end(),0)
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
typedef long long ll;
const int INTINF = 1<<29;
const ll LLINF = 1LL<<61;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
const int DX[8]={ 0, 1, 0,-1, 1, 1,-1,-1};
const int DY[8]={ 1, 0,-1, 0, 1,-1, 1,-1};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> v;
  int n,m;
  cin >> n >> m;
  int a,b;
  int MAX_N = 8;
  int link[MAX_N][MAX_N];
  REP(i,MAX_N)REP(j,MAX_N)link[i][j]=0;
  REP(i,n){
      v.push_back(i);
  }
  REP(i,m){
      cin >> a >> b;
      link[a-1][b-1]=1;
      link[b-1][a-1]=1;
  }
  int ans = 0;
  do{
      //REP(i,n){cout << v[i];}
      //cout << endl;
      if (v[0]!=0)continue;
      bool flag = true;
      REP(i,n-1){
          if (link[v[i]][v[i+1]] == 0)flag = false;
      }
      if (flag)ans++;
  }while(next_permutation(ALL(v)));

  cout << ans << endl;
}
