#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;

int main(void){
	int N;
	cin >> N;
	vector<int> H(N);
	for(int i = 0; i < N; i++) cin >> H[i];

	int res = 0;
	int M = H[0];
	for(int i = 0; i < N; i++){
		if(M <= H[i]) res++;
		M = max(M, H[i]);
	}

	cout << res << '\n';

	return 0;
}