#include <bits/stdc++.h>
using namespace std;

#define int long long

int N, M, K;
vector<int> D;
vector<int> is_d;
vector<vector<int> > v;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> N >> M >> K;

  D = vector<int>(M);
  is_d = vector<int>(N, -1);  
  for ( int i = 0; i < M; i++ ) {
    cin >> D[i];    
    is_d[--D[i]] = i;    
  }

  v = vector<vector<int> >(N, vector<int>(K));
  for ( int i = 0; i < N; i++ ) {
    for ( int j = 0; j < K; j++ ) {
      cin >> v[i][j];
      v[i][j]--;
    }
  }

  using Pii = pair<int, int>;
  queue<Pii> Q;
  Q.push(Pii((1<<M)-1, 0));
  vector<bool> used(1<<M, false);
  while ( !Q.empty() ) {
    Pii q = Q.front(); Q.pop();
    int b = q.first, c = q.second;

    if ( b == 0 ) {
      cout << c << endl;
      break;
    }

    if ( used[b] ) continue;
    used[b] = true;

    for ( int i = 0; i < K; i++ ) {
      int nb = 0;
      for ( int j = 0; j < M; j++ ) {
	if ( !((1<<j)&b) ) continue;
	int u = v[D[j]][i];
	if ( is_d[u] >= 0 ) nb |= (1<<is_d[u]);
      }
      Q.push(Pii(nb, c+1));      
    }
  }
  
  return 0;
}

