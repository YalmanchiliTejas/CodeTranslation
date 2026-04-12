#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int R[10];
int d[10][10];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) R[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		d[a][b] = 1;
		d[b][a] = 1;
	}
	int ans = 0;
	do {
		bool plus = true;
		if (R[0] != 0) continue;
		for (int i = 0; i < N - 1; i++) {
			if (d[R[i]][R[i + 1]] == 0) {
				plus = false;
				break;
			}
		}
		if (plus) ans++;
	} while (next_permutation(R, R + N));
	cout << ans << endl;
}
