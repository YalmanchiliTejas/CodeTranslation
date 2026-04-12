#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<fstream>
#include<sstream>
#include<vector>
#include<set>
#include<deque>
#include<cstring>
#include<queue>
#include<stdio.h>
#include<set>
#include<stack>
#include<numeric>
#include<map>
#include<cstdio>
#include<bitset>
#include<array>
#include<list>
using namespace std;
#define ll long long 
const ll mod = 1e9 + 7;

ifstream f1;
ofstream f2;

vector<stack<ll>> res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	f1.open("INP.txt");
	f2.open("OUT.txt");
	ll n;
	cin >> n;
	stack<ll> hold;
	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;
		hold.push(x);
		if (i == 0) {
			res.push_back(hold);
			continue;
		}
		ll sub = -1;
		ll l = 0, r = res.size() - 1;
		while (l <= r) {
			ll mid = (l + r) / 2;
			if (res[mid].top() < x) {
				r = mid - 1;
				sub = mid;
			}
			else {
				l = mid + 1;
			}
		}
		if (sub < 0) {
			res.push_back(hold);
		}
		else {
			res[sub].push(x);
		}
		hold.pop();
	}
	cout << res.size() << endl;
	//system("pause");
	return 0;
}