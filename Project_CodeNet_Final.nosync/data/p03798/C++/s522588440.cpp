#include<bits/stdc++.h>
using namespace std;
char dat[100001];
bool z[100001]; 
int main()
{
	int n;
	cin>>n;
	cin>>dat;
	dat[0];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			z[0]=i;
			z[1]=j;
			for(int k=1;k<n-1;k++)
			{
				z[k+1]=z[k-1]^z[k]^(dat[k]=='x');
			}
			if((dat[n-1]=='x')==(z[n-2]^z[n-1]^z[0])&&(dat[0]=='x')==(z[n-1]^z[0]^z[1]))
			{
				for(int k=0;k<n;k++)
				{
					cout<<(z[k]?'W':'S');
				}
				cout<<endl;
				return 0;
			}
		}
	}
	cout<<-1<<endl;
	return 0;
}