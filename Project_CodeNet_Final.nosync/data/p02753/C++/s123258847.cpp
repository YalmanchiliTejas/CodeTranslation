#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	bool a = false, b = false;
	for(auto i : s)
		if(i == 'A') a = true;
		else if(i == 'B') b = true;
	if(a && b) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}