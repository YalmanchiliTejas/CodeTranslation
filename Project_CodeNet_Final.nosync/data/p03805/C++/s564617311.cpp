#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)

bool is_exist(vector<vint> &G,int v,int nv){
  for (auto k :G[v]){
    if (k==nv) return true;
  }
  return false;
}

int main() {
  int n,m;
  int a,b;
  cin >> n >> m;
  vector<vint> graph(n);
  int arry[n];
  rep(h,n){
    arry[h]=h;
  }
  rep(i,m){
    cin >> a >> b;
    graph.at(a-1).push_back(b-1);
    graph.at(b-1).push_back(a-1);
  }
  int cnt=0;
  do{
     for(int i=0; i < n ;i++){
      if (i==n-1){
        cnt++;
        break;
      }
      if (!is_exist(graph,arry[i],arry[i+1])) break;
     }
  }while(next_permutation(arry+1,arry+n));
          
  cout << cnt << endl;
    
      
  return 0;
}