#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,k;
	string s;
	cin>>n>>s>>k;
	for(auto i:s) cout<<(i==s[k-1]?i:'*');
	cout<<"\n";
	return 0;
}