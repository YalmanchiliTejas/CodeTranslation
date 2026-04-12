#include<bits/stdc++.h>

using namespace std;

#define int long long
string n;
int d,f[20004][2][205],base=1e9+7;
int F(int i,int ok,int du)
{
	if(f[i][ok][du]!=-1) return f[i][ok][du];
	else if(i==n.length()+1) 
	{
		if(du==0) return 1;
		else return 0;
	}
	else
	{
		int res=0;
		if(ok==0)
		{
			for(int j=0;j<(int)(n[i-1]-'0');j++)
			{
				res=(res+F(i+1,1,(du+j)%d))%base;
			}
			res=(res+F(i+1,0,(du+(int)(n[i-1]-'0'))%d))%base;
		}
		else
		{
			for(int j=0;j<=9;j++)
			{
				res=(res+F(i+1,1,(du+j)%d))%base;	
			}
		}
		f[i][ok][du]=res;
		return res;
	}
}
main()
{
	cin>>n>>d;
	memset(f,-1,sizeof(f));
	cout<<(F(1,0,0)-1+base)%base;
}