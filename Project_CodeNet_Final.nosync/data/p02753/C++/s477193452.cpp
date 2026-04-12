#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
int main()
{
	string str;
	cin>>str;
	bool f=false;
	for(int i=0;i<str.size()-1;i++)
	{
		if(str[i]!=str[i+1])
		{
			f=true;
			break;
		}
	}
	if(f)
	cout<<"Yes"<<endl;
	else
	cout<<"No"<<endl;
}
