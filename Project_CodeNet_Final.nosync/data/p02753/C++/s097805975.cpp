#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <bits/stdc++.h>
#define SIZE 2005
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define mp make_pair
#define ll long long
using namespace std;
void io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
ll n, m, k, a, b, ans;
string s;
map<char, int> MP;
int main() {
	io(); cin >> s;
	rep(i, 0, 2) MP[s[i]]++;
	if (MP.size() > 1) cout << "Yes";
	else cout << "No";
}