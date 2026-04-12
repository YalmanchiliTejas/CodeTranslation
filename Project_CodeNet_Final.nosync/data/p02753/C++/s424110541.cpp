#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);
using namespace std;
typedef long long ll;
typedef long double ld;


int main(){
	string s; cin >> s;
	bool a = false, b = false;
	for(char c: s){
		if (c == 'A') a = true;
		if (c == 'B') b = true;
	}
	if (a and b) puts("Yes");
	else puts("No");
	return 0;
}
