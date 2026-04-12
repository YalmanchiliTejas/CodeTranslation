#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll h,w;cin>>h>>w;ll count=0;
	
	char a[h][w];ll row[h];ll col[w];
	for(int i=0;i<h;i++)
	{
		ll cr=0,cc=0;
		for(int j=0;j<w;j++)
		 {
		   cin>>a[i][j];
		   if(a[i][j]=='.')
		     cr++;
	 
		 
		 }
		 if(cr==w)
		   row[i]=1;
		 else
		   count++;  
		 cr=0;  
	}
	
	char b[count][w];ll k=0;
	for(int i=0;i<h;i++)
	{
		if(row[i]!=1){
		
		for(int j=0;j<w;j++)
		{
		b[k][j]=a[i][j];	
		}
		k++;
	    }
	   
	}
	
	int p[w];
	for(int j=0;j<w;j++)
	{
		ll cw=0;
		for(int i=0;i<count;i++)
		{
			if(b[i][j]=='.')
			   cw++;
		}
		
		if(cw==count)
		  p[j]=1;
	}
	
	
	for(int i=0;i<count;i++)
	{
		
	for(int j=0;j<w;j++)
		{
		if(p[j]!=1)
		   cout<<b[i][j];	
		}
		cout<<endl;
	    
    
	}
	
	
	
}