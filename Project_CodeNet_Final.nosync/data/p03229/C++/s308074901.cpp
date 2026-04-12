#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
using namespace std;
typedef long long ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
//ll dp[int(1e9)][int(1e9)];
ll temp[100][100];
int h = 0;


int main()
{
	int n;
	cin >> n;
	vector<ll> f(n);
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}
    ll temp = 0;
	ll answer = 0;
	sort(f.begin(), f.end());
	if (n % 2 == 0) {
		for (int i = 0; i < n; i++) {
			if (n / 2 > i) {
				answer -= f[i] * 2;
				//cout << f[i] << endl;
			}
			else {
				answer += f[i] * 2;
				//cout << f[i] << "!" << endl;
			}
		}
		answer = answer - f[n / 2] + f[n / 2 - 1];
	}
	else {
		for (int i = 0; i < n; i++) {
			if ((n+1) / 2 > i) {
				answer -= f[i] * 2;
				//cout << f[i] <<"a"<< endl;
			}
			else {
				answer += f[i] * 2;
				//cout << f[i] << "!" << endl;
			}

			if (n / 2 > i) {
				temp -= f[i] * 2;
				//cout << f[i] << "a" << endl;
			}
			else {
				temp += f[i] * 2;
				//cout << f[i] << "!" << endl;
			}

		}
		//cout << f[(n - 1) / 2 + 1] << " " << f[(n - 1) / 2 + 2] << endl;
		answer = answer + f[(n+1) / 2-1] + f[(n+1) / 2-2];
		temp = temp - f[(n - 1) / 2 + 1] - f[(n - 1) / 2 ];

	}

	
		cout << max(answer,temp) << endl;
}