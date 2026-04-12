#include <bits/stdc++.h>
using namespace std;
int main(){
	int a=0;
	string s;
	cin>>s;
	for(int i=0;i<s.size()-1;i++) if(s[i]=='A'&&s[i+1]=='C') a++;
	if(a) cout<<"Yes";
	else cout<<"No";
	return 0;
}
