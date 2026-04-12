#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

	
	
int main(int argc, char *argv[]) {
	
	int N; cin >> N;

	int M = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int h; cin >> h;
		if (h >= M) {
			cnt++;
		}
		M = max(M, h);
	}
	cout << cnt << endl;

	return 0;
}
