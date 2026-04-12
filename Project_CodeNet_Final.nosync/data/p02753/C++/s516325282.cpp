#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

string s;

int main() {
	cin >> s;
	if(s[0] != s[1] || s[1] != s[2] || s[2] != s[0]) return cout << "Yes", 0;
	cout << "No";
}