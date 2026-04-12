#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	string s;
	cin >> N >> s;
	vector<int> b(N);
	for (b[0] = 0; b[0] < 2; b[0]++) {
		for (b[1] = 0; b[1] < 2; b[1]++) {
			for (int i = 2; i < N; i++) {
				b[i] = (s[i - 1] != 'o') ^ (b[i - 1] ^ b[i - 2]);
			}
			if ((b[N - 2] ^ b[N - 1] ^ b[0]) != (s[N - 1] != 'o')) continue;
			if ((b[N - 1] ^ b[0] ^ b[1]) != (s[0] != 'o')) continue;
			for (int i = 0; i < N; i++) {
				printf("%c", "SW"[b[i]]);
			}
			puts("");
			return 0;
		}
	}
	puts("-1");
	return 0;
}
