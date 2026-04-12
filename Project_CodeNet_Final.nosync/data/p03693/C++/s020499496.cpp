#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	string s;
	s=to_string(a)+to_string(b)+to_string(c);
	int sum = stoi(s);
	if(sum%4==0)puts("YES");
	else puts("NO");
	return 0;
}