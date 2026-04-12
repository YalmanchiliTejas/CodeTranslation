#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <bits/stdc++.h>
#define SIZE 500010
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define ll long long
#define ull unsigned long long
#define mp make_pair
using namespace std;
void io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
int n, m;

int main() {
	io(); cin >> n >> m;
	if (n == m) cout << "Yes\n";
	else cout << "No\n";
}