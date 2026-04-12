#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <math.h>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string N;
	int K;
	vector<int>v(101,0);
	for (int i = 1; i < 101; i++) {
		v[i] = v[i - 1] + i;
	}
	long long int ans=0;
	cin >> N >> K;
	if (N.length() < K) {
		cout << ans;
		return 0;
	}
	if (K == 1) {
		char a = N[0];
		int b = a - '0';
		ans = N.length() * 9-(9-b);
	}
	else if (K == 2) {
		char a = N[0];
		int b = a - '0';
		int tmplen, tmpi;
		tmplen = N.length()-1;
		ans = (N.length() - 1) * 9 * (b-1);
		while (tmplen != 1) {
			ans += (tmplen - 1) * 9 * 9;
			tmplen--;
		}
		for (int i = 1; i < N.length(); i++) {
			if(N[i]!='0') {
				tmplen = N.length() - i;
				tmpi = i;
				break;
			}
			if (i == N.length() - 1) {
				cout << ans;
				return 0;
			}
		}
		a = N[tmpi];
		b = a - '0';
		ans += tmplen * 9 - (9 - b);
	}
	else {
		char a = N[0];
		int b = a - '0';
		int tmplen,tmpi, t=N.length()-3;
		ans += v[t+1] * 81 * (b - 1);
		while (t != 0) {
			ans += v[t] * 81 * 9;
			t--;
		}
		for (int i = 1; i < N.length(); i++) {
			if (i == N.length() - 1) {
				cout << ans;
				return 0;
			}
			if(N[i]!='0') {
				tmplen = N.length() - i;
				tmpi = i;
				break;
			}
		}
		a = N[tmpi];
		b = a - '0';
		int len = tmplen;
		tmplen -= 1;
		ans += (len - 1) * 9 * (b - 1);
		while (tmplen != 1) {
			ans += (tmplen - 1) * 9 * 9;
			tmplen--;
		}
		for (int i = tmpi+1; i < N.length(); i++) {
			if(N[i]!='0') {
				tmplen = N.length() - i;
				tmpi = i;
				break;
			}
			if (i == N.length() - 1) {
				cout << ans;
				return 0;
			}
		}
		a = N[tmpi];
		b = a - '0';
		ans += tmplen * 9 - (9 - b);
	}
	cout << ans;
	return 0;

}