#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int main()
{
	string s;
	cin >> s;
	sort(s.begin(),s.end());
	if(s[0]=='A'&&s[2]=='B')
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	
	return 0;
}