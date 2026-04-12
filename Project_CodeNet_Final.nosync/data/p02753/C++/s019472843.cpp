#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
ll strtoint(string str);
int main(){
	fast;
	string s; cin>>s;
	if(s[0]=='A'&&s[1]=='A'&&s[2]=='A' || s[0]=='B'&&s[1]=='B'&&s[2]=='B')cout<<"No\n";
	else
		cout<<"Yes\n";
	return 0;
}
ll strtoint(string str){
	ll x=0;
	stringstream ss;
	ss<<str;
	ss>>x;
	return x;
}