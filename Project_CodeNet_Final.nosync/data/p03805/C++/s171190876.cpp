#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

int main(){
  ll N, M;
  cin >> N >> M;
  vvl graph(N + 1, vl(N + 1, 0));
  ll a, b;
  rep(i, M){
    cin >> a >> b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }

  ll cnt = 0;
  
  vl n(N);
  iota(n.begin(), n.end(), 1);

  do{
    if(n[0] == 1){
      bool path = true;

      rep2(i, 1, N){
	if(graph[ n[i - 1] ][ n[i] ] == 0){
	  path = false;
	  break;
	}
      }
      
      if(path) cnt++;
    }
  } while( next_permutation(n.begin(), n.end()) );

  cout << cnt << endl;
  
  return 0;
}