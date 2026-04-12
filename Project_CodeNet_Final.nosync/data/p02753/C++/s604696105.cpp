#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	ll i,q=0,w=0;
	cin>>s;
	for(i=0;i<s.length();i++) {
		if(s[i]=='A') q=1;
		else w=1;
	}
	if(q==1 && w==1) cout<<"Yes";
	else cout<<"No";
	
}