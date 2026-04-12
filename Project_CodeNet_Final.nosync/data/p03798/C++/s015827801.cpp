#include<bits/stdc++.h>
using namespace std;
string s;
int n;
bool sp[100000];//0羊,1狼 
bool ok;
int main()
{
	cin>>n>>s;
	for(int f=0;f<2;f++)
	{
		for(int e=0;e<2;e++)
		{
			sp[0]=f;
			sp[1]=e;
			for(int l=2;l<n;l++)
			{
				if(sp[l-1])
				{
					if(s[l-1]=='x')sp[l]=sp[l-2];
					else if(s[l-1]=='o')sp[l]=1^sp[l-2];
				}
				else 
				{
					if(s[l-1]=='x')sp[l]=1^sp[l-2];
					else if(s[l-1]=='o')sp[l]=sp[l-2];
				}
			}
			if(sp[0]==1&&((s[0]=='o'&&sp[n-1]!=sp[1])||(s[0]=='x'&&sp[n-1]==sp[1])))
			{
				if(sp[n-1]==1&&((s[n-1]=='o'&&sp[n-2]!=sp[0])||(s[n-1]=='x'&&sp[n-2]==sp[0])))ok=1;
				else if(sp[n-1]==0&&((s[n-1]=='o'&&sp[n-2]==sp[0])||(s[n-1]=='x'&&sp[n-2]!=sp[0])))ok=1;
			}
			else if(sp[0]==0&&((s[0]=='o'&&sp[n-1]==sp[1])||(s[0]=='x'&&sp[n-1]!=sp[1])))
			{
				if(sp[n-1]==1&&((s[n-1]=='o'&&sp[n-2]!=sp[0])||(s[n-1]=='x'&&sp[n-2]==sp[0])))ok=1;
				else if(sp[n-1]==0&&((s[n-1]=='o'&&sp[n-2]==sp[0])||(s[n-1]=='x'&&sp[n-2]!=sp[0])))ok=1;
			}
			if(ok)
			{
				for(int i=0;i<n;i++)
				{
					if(sp[i])cout<<"W";
					else cout<<"S";
				}
				return 0;
			}
		}
	}
	cout<<"-1";
	return 0;
}