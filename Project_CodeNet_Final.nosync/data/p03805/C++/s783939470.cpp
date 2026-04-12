#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<functional>
#include<stack>
#include<queue>
#include<cmath>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
# define MOD 1000000000+7
# define INF 1000000000
typedef long long ll;
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int main() {

	int n = 0, m = 0,a,b;
	int ans = 0,r = 0;
	vector<int> v;
	bool list[100][100] = {false};
	cin >> n >> m;
	rep(i, m) {
		cin >> a >> b;
		list[a - 1][b - 1] = true;
		list[b - 1][a - 1] = true;
	}
	rep(i, n) {
		v.push_back(i);
	}


	do {

		for(int i = 0; i < n - 1; i++){

			if (list[v[i]][v[i + 1]] == true || list[v[i + 1]][v[i]] == true) {
				r++;
			}
		}

		if (r == n - 1 && v[0] == 0) ans++;

		r = 0;

	} while (next_permutation(v.begin(), v.end()));
	
	cout << ans << endl;
	return 0;

}