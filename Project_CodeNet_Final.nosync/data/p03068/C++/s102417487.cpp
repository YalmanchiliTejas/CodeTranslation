#include <bits/stdc++.h>

using namespace std;
inline void FAST_IO(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

int main(){
	FAST_IO();
	
	int n,k;
	string s;
	cin >> n >> s >> k;
	
	char at = s[k-1];
	
	for(char &c : s)
		if(c != at)
			c = '*';
	
	cout << s << endl;
	
	return 0;
}