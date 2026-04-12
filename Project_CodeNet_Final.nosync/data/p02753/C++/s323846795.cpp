#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s; cin >> s;
	sort(s.begin(), s.end());
	if(s[0] == s[2]) cout << "No\n";
	else cout << "Yes\n";
}