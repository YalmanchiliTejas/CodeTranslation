#include <iostream>
#include<algorithm>
#include <vector>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define max(x,y) (((x)>(y)) ? x:y)
#define min(x,y) (((x)<(y)) ? x:y)
#define FOR(a,b,c) for(b=(c);b<(a);b++)
#define ender {return 0;}
#define tosasuretu(a) (a*(a+1)/2)
inline ll kaizyo(ll);
ll combination(ll, ll);
int main() {
	int w, h;
	cin >> h >> w;
	vector<string> a, ans;
	for (int i = 0; i < h; i++) {
		string get;
		cin >> get;
		bool checker = false;
		for (unsigned int j = 0; j < get.size(); j++) {
			if (get[j] == '#') {
				checker = true;
				break;
			}
		}
		if (checker) {
			a.push_back(get);
		}
	}
	bool checking[100];
	for (unsigned int k = 0; k < a[0].size(); k++) {
		checking[k] = false;
		for (int l = 0; l < a.size(); l++) {
			if (a[l][k] == '#') {
				checking[k] = true;
				break;
			}
		}
	}
	for (unsigned int m = 0; m < a.size(); m++) {
		for (int n = 0; n < a[m].size(); n++) {
			if (checking[n]) {
				cout << a[m][n];
			}
		}
		cout << endl;
	}
	return 0;
}


inline ll kaizyo(ll x) {
	long ans = 1;
	for (int z = 0; z < x; z++) {
		ans *= (x - z);
	}
	return ans;
}
