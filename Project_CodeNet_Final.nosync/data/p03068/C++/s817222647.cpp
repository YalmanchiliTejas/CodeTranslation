#include <bits/stdc++.h>
using namespace std;

signed main(){
	int k,n;
	string s;
	cin >> n >> s >> k;
	for(int i = 0;i < n;i++){
		if(s[i] == s[k - 1]) cout << s[i];
		else cout << "*";
	}
	cout << endl;
}