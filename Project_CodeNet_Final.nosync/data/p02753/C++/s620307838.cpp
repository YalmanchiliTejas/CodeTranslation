#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;
	int c1 = 0, c2 = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'A') c1++;
		if(s[i] == 'B') c2++;
	}
	if(c1 != 0 && c2 != 0)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
