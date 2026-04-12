#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MAX = 1000;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L

int main() {
	int N; cin >> N;
	vector<unsigned long long> v;
	vector<unsigned long long> w;
	rep(i,N) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		if (i==0) w.push_back(temp);
		else w.push_back(temp+w[i-1]);
	}
	unsigned long long ans = 0;
	unsigned long long max = 1e9 + 7;
	for (int ii = 0; ii < N; ii++) {
		unsigned long long temp = w[N-1]-w[ii];
		unsigned long long temp2;
		temp2 = (ans % max) + (v[ii] % max) * (temp % max);
		ans = temp2 % max;
	}
	cout << ans << endl;
}