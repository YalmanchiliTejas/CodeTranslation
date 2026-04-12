#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cstring>
#include<iomanip>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	int a[12];
	for(int i=0;i<12;i++)
	{
		cin>>a[i];
	}
	sort(a,a+12);
	int f=0;
	for(int i=0;i<3;i++)
	{
		if(a[i*4]==a[i*4+1]&&a[i*4+1]==a[i*4+2]&&a[i*4+2]==a[i*4+3])
		{
			f+=1;
		}
	}
	if(f==3)cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}