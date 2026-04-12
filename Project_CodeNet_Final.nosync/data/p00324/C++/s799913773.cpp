#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	map<long long, int> m;
	int ans = 0;
	long long num = 0;
	m[0] = -1;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		num += a;
		map<long long, int>::iterator itr = m.find(num);
		if (itr == m.end()) {
			m[num] = i;
		}
		else {
			ans = max(ans, i - m[num]);
		}
	}
	cout << ans << endl;
	return 0;
}