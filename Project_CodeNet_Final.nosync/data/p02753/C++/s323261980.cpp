#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	bool a = false, b = false;
	for(int i = 0; i < s.size(); i++)
		if(s[i] == 'A') a = true;
		else if(s[i] == 'B') b = true;
	if(a && b) printf("Yes\n");
	else printf("No\n");
	return 0;
}