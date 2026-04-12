#pragma GCC optimize ("Ofast")

#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING

#include <bits/stdc++.h>
using namespace std;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);


	int x; cin >> x;
	cout << (x >= 30?"Yes": "No");
	
	return 0;
}