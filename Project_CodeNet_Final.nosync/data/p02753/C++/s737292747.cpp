#include <bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main()
{
	string s;
	cin >>s;
	for(int i=0;i<3;i++) mp[s[i]]++;
	if(mp['A']&&mp['B']) cout <<"Yes"<<endl;
	else cout <<"No"<<endl;
}