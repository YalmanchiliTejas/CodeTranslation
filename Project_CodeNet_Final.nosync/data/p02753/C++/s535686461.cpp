#include <bits/stdc++.h>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cout.tie(0);
cin.tie(NULL);
string s; cin>>s;
int a=0,b=0;
for(int i=0;i<3;i++)
{
	if(s[i]=='A')
	a++;
	else
	b++;
}
if(a==0||b==0)
cout<<"No";
else
cout<<"Yes";
}