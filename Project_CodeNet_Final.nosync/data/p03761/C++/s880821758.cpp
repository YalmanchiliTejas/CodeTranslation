#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <complex>
#include <vector>
#include <cstdio>
#include <cmath>
#include <time.h>
#define all(c) ((c).begin(),(c).end())
#define rall(c) (c).rbegin(),(c).rend()
//#define sort(v,n) sort(v,v+n)
#define vsort(v) sort(v.begin(),v.end())
#define vvsort(v) sort(v.begin(),v.end(),greater<int>())
#define ll long long
#define pb(a) push_back(a)
#define fi first
#define se second
#define inf 999999999
using namespace std;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);
//---------------------------------------------------------------------------------------------//
int n;
string s;
string ans;
int main() {
	cin >> n;
	int cont = 0;
	while (cont < n) {
		cin >> s;
		sort(s.begin(), s.end());
		if (cont == 0) {
			ans = s;
			cont++;
			continue;
		}
		string t="";
		int i = 0, j = 0;
		while (i < ans.length() && j < s.length()) {
			if (ans[i] == s[j]) {
				t += ans[i];
				i++;
				j++;
			}
			else if (ans[i] > s[j]) {
				j++;
			}
			else {
				i++;
			}
		}
		ans = t;
		cont++;
	}
	cout << ans << endl;
}