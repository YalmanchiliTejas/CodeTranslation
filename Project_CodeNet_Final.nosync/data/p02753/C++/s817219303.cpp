#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0),cin.sync_with_stdio(0),cout.tie(0),cout.sync_with_stdio(0);
	string s;
	cin>>s;
	if(s[0]==s[1] && s[1]==s[2])
		cout<<"No";
		else cout<<"Yes";
}
