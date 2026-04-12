#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#define ll long long
#define dd double
using namespace std;

int main() {
	ll n;
	string s;
	ll m;
	while (cin >> n) {
		cin >> s;
		cin >> m;
		char x = s[m - 1];
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] != x) {
				cout << '*';
			}
			else {
				cout << s[i];
			}
		}
		cout << endl;
	}
}