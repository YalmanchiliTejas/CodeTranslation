#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)




int N, M;
int E[10][10];
int idx[10];
//-----------------------------------------------------------------
int main() {
	cin >> N >> M;
	rep(i, 0, M) {
		int a, b; cin >> a >> b;
		E[a][b] = E[b][a] = 1;
	}
	
	int ans = 0;
	idx[0] = 1;
	rep(i, 1, N) idx[i] = i + 1;
	do {
		ans++;
		rep(i, 0, N - 1) {
			int a = idx[i];
			int b = idx[i + 1];
			if (!E[a][b]) {
				ans--;
				break;
			}
		}
	} while (next_permutation(idx + 1, idx + N));
	cout << ans << endl;
}