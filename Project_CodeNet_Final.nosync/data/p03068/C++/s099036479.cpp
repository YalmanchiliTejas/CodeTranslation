#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ll n,k;
	string s;
	cin>>n>>s>>k;
	k--;
	char c=s[k];
	for(int i=0;i<s.size();i++)if(s[i]!=c)s[i]='*';
	cout<<s;
	return 0;
}