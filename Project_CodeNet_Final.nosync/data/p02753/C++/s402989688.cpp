#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
	cin >> s;
	sort(s.begin(),s.end());
	if(s[0] != s[2]) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
