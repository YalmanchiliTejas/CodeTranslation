# include <bits/stdc++.h>
using namespace std;
long long a1,b1;
string s;
int main()
{
	cin>>s;
	if (s[0]=='A' || s[1]=='A' || s[2]=='A')
	a1++;
		if (s[0]=='B' || s[1]=='B' || s[2]=='B')
	b1++;
	if (a1!=0 && b1!=0)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	cout<<"No"<<endl;
}