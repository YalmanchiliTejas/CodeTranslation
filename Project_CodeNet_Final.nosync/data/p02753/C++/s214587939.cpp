#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<set>
using namespace std;
#define LL long long
int main() 
{
	string s;
	cin>>s;
	int flag1,flag2;
	flag1=flag2=0;
	for(int i=0;i<3;i++)
	{
		if(s[i]=='A')
			flag1=1;
		if(s[i]=='B')
			flag2=1;
	}
	if(flag1&&flag2)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

}


