# include <bits/stdc++.h>
using namespace std;
const int maxn=100+50;
int main ()
{
	int a,b;
	cin>>a>>b;
	char s[maxn][maxn];
	int m[maxn]={0},x[maxn]={0};
	for (int i=1;i<=a;++i)
	   	 for (int j=1;j<=b;++j)
	   	     cin>>s[i][j];
	for (int i=1;i<=a;++i)
	    {
	    	int sum=0,j;
	    	for ( j=1;j<=b;++j)
	    	   	if (s[i][j]=='#')
	    	   	     break;
	            if (j==b+1)
                   m[i]=1;
		}
		for (int j=1;j<=b;++j)
	    {
	    	int sum=0,i;
	    	for (i=1;i<=a;++i)
	    	   	if (s[i][j]=='#')
	    	   	     break;
	        if (i==a+1)
	             x[j]=1; 
		}
		for (int i=1;i<=a;++i)
		    {
		    	if (m[i]==1) continue;
		      for (int j=1;j<=b;++j)
		           if (!x[j])
		   	       printf ("%c",s[i][j]);
			  printf ("\n");	
			}
	return 0;
} 