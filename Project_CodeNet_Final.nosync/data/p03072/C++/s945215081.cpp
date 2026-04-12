#include "bits/stdc++.h"
using namespace std;
#define REP(i,a) for(int i = 0; i < (a);i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;
using Graph = vector < vector<int>>;
long int sum[200020] = {};
int main() {
	int N;
	cin >> N;
	vector<int> s;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		s.push_back(a);
	}
	int max = s[0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (s[i] >= max) {
			cnt++;
			max = s[i];
		}
	}
	cout << cnt;
}