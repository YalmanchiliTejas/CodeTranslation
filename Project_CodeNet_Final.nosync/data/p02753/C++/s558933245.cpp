#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int a=0,b=0;
	cin>>s;
	for(int i=0;i<=2;i++)
	{
		if(s[i]=='B') b++;
		if(s[i]=='A') a++;
	}
	if(b==2&&a==1||a==2&&b==1)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
    cout<<"No"<<endl;
    return 0;
}