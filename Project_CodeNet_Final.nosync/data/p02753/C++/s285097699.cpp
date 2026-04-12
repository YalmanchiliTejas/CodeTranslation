#include<bits/stdc++.h>
using namespace std;
#define long long int
signed main()
{
	string s;
	while(cin>>s)
	{
		map<char,int> m;
		for(int i=0;i<3;i++) m[s[i]]++;
		if(m.size()==1) cout<<"No\n";
		else cout<<"Yes\n";
	}
} 