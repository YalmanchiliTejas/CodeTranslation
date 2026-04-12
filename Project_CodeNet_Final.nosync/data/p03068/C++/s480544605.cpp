#include <bits/stdc++.h>
using namespace std;

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	string s;
	cin >> n >> s >> k;
	for (int i=0; i<n; i++){
		if (s[i]!=s[k-1]) s[i]='*';
	}
	cout << s << "\n";
}