#include<bits/stdc++.h>
using namespace std;
int i,j,m,n,p,ii,o;
int a[105][105];
int r[105],c[105];
int main()
{
  char u;
  cin>>m>>n;
  //read
   for(i=1;i<=m;i++)
   {
   	 int t=0;
  	 for(j=1;j<=n;j++)
   	 {
   	 	cin>>u;
   	 	if(u=='#') a[i][j]=0;
   	 	else {
   	 	a[i][j]=1;
   	 	t++;
   	     }
   	 }
     r[i]=t;
     
   }
    
   //column
   for(j=1;j<=n;j++)
   {
   	 int t=0;
   	 for(i=1;i<=m;i++)
   	 {
   	 	if (a[i][j]==1) t++;
   	 }
   	 c[j]=t;
  
   }
    
   
   for(i=1;i<=m;i++)
   {
   	  int t=0;
   	 for(j=1;j<=n;j++)
   	 {
   	 	
   	   if(r[i]!=n&&c[j]!=m)
		{
			t=1;
		   if (a[i][j]==0) cout<<"#";
   	 	   if (a[i][j]==1) cout<<".";
         	 }
    }
   	 if (t) cout<<endl; 
   }
  return 0;
}
