#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int h,w;
	while(cin>>h>>w)
	{
		char a[h][w];
		string str="";
		int i,j;
		int th=h,tw=w;
		for(i=0;i<h;i++)
			for(j=0;j<w;j++)
				cin>>a[i][j];
		for(i=0;i<h;i++)
		{
			int cnt1=0;
			for(j=0;j<w;j++)
			{
				if(a[i][j]=='.')
					cnt1++;	
			}
			if(cnt1==w)
			{
				th--;
				for(j=0;j<w;j++)
					a[i][j]='!';
			}
				

		}
		
		
		for(j=0;j<w;j++)
		{
			int cnt2=0;
			for(i=0;i<h;i++)
			{
				if(a[i][j]=='.'||a[i][j]=='!')
					cnt2++;
			}
			if(cnt2==h)
			{
				tw--;
				for(i=0;i<h;i++)
					a[i][j]='!';
			}
				
		}
	
		for(i=0;i<h;i++)
		{
			for(j=0;j<w;j++)
				if(a[i][j]!='!')
					str+=a[i][j];
					
		}
	//	cout<<th<<" "<<tw<<endl;
		for(i=0;i<th*tw;i++)
		{
			if(i%tw==0)
				cout<<endl;
			cout<<str[i];
		}
		 cout<<endl;
			
			
	} 	
	return 0;
}
