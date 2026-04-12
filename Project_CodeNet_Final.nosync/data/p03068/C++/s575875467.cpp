#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>

using namespace std;
using lli = long long int;

int main() {
	int N, K;
	string s;
	cin >> N;
	cin >> s;
	cin >> K;
	for (int i = 0; i < N; i++) {
		if (s[K - 1] != s[i]) {
			s[i] = '*';
 		}
	}
	cout << s << endl;
	return 0;
}
