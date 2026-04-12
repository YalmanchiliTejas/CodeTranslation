#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18,MOD=1e9+7;
int main(){
	ll n,k;
	string s;
	cin>>n>>s>>k;
	k--;
	for(int i=0;i<s.length();i++){
		if(s[i]==s[k])cout<<s[i];
		else cout<<"*";
	}
	cout<<endl;
}
