#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#include<set>
#include<queue>
#include<map>
#pragma comment(linker, "/STACK:66777216")

using namespace std;

#define ll long long
#define ld long double


int main() {
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ll a, b;
	cin >> a;
	string s;
	cin >> s >> b;
	for (ll i = 0; i < s.length(); i++) {
		if (s[i] != s[b-1])s[i] = '*';
	}
	cout << s;
	





}