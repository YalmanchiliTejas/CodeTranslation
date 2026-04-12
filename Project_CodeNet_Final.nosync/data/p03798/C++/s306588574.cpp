#include<iostream>
#include<cstdio>
using namespace std;

int zz[100005],n;
string dat;

int main()
{
	cin>>n>>dat;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		{
			zz[0]=i;
			zz[1]=j;
			for(int k=1;k<n-1;k++)
			{
				zz[k+1]=zz[k]^zz[k-1]^(dat[k]=='x');
			}
			if((dat[n-1]=='x')==(zz[n-2]^zz[n-1]^zz[0]) && (dat[0]=='x')==(zz[n-1]^zz[0]^zz[1]))
			{
				for(int k=0;k<n;k++)
					cout<<(zz[k]?"W":"S");
				cout<<endl;
				return 0;
			}
		}
	cout<<"-1"<<endl;
	return 0;
}