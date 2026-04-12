#include <bits/stdc++.h>
using namespace std;

void solve(long long N, long long M, vector<long long> a, vector<long long> b){
	vector<int> nodes;
  int paths[9][9] = {0};
  for (int i = 0; i < N; i++) {
    nodes.push_back(i + 1);
  }
  for (int i = 0; i < M; i++) {
    paths[a[i]][b[i]] = 1;
    paths[b[i]][a[i]] = 1;
  }
  int ans = 0;
  do {
    if (nodes[0] != 1) continue;
    bool valid = true;
    for (int i = 1; i < N; i++) {
      if (paths[nodes[i-1]][nodes[i]] == 0) {
        valid = false;
        break;
      }
    }
    if (valid) ans++;
  } while (next_permutation(nodes.begin(), nodes.end()));
  cout << ans << endl;
}

int main(){	
	long long M;
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&M);
	vector<long long> b(M-1+1);
	vector<long long> a(M-1+1);
	for(int i = 0 ; i <= M-1 ; i++){
		scanf("%lld",&a[i]);
		scanf("%lld",&b[i]);
	}
	solve(N, M, a, b);
	return 0;
}

