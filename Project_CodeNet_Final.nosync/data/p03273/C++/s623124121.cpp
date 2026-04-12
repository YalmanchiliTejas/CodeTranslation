#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
#define LL long long
#define N 10000
#define Inf 0x7fffffff
int a[102][102];
int main()
{
    ios::sync_with_stdio(false);
    int n,m,i,j;
    int co1=0;
    char x;
    while(cin>>n>>m)
    {
    	memset(a,0,sizeof(a));
    	for(i=0;i<n;i++)
        {
        	for(j=0;j<m;j++)
            {
      	        cin>>x;
      	        if(x=='#')
               	{
               		a[i][j]=1;
				}
             	else
      	        {
      	        	a[i][j]=0;
      	         	++co1;
				}
	        }
	
	        if(co1==m)
	            a[i][0]=-2;	
			co1=0;
		}
	    for(i=0;i<m;i++)
	    {
	    	co1=0;
	    	for(j=0;j<n;j++)
	    	{
	    		if(a[j][i]!=1)
	    		{
               		co1++;
	            }
			}
			if(co1==n)
	        for(j=0;j<n;j++)
	        if(a[j][i]!=-2)
	        a[j][i]=-1;
		}

		for(i=0;i<n;i++)
		{
			if(a[i][0]==-2)
			continue;
			for(j=0;j<m;j++)
			{
				if(a[i][j]==1)
				cout<<'#';
				else if(a[i][j]==0)
				cout<<'.';
			}
			cout<<endl;
		}
		
	}
    return 0;
}
