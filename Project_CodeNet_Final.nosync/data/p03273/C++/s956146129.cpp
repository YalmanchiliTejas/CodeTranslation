#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n,m,i,j;
	cin>>n>>m;
	char mat[n][m];
	int row[n],col[m];
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	
	for(i=0;i<n;i++)
	  {
	  	 for(j=0;j<m;j++)
	  	   {
	  	   	cin>>mat[i][j];
	  	   	if(mat[i][j]=='#')
	  	   	  {++row[i];col[j]++;}
	  	   }
	  }
	  //cout<<row[0]<<" "<<col[0]<<"\n";
	for(i=0;i<n;i++)
	  {    int c=0;
	  	for(j=0;j<m;j++)
	  	  {
	  	  	if(row[i]!=0 && col[j]!=0){c=1;
	  			cout<<mat[i][j];
	  	  		
	  	  	}	
	  	  }
	     if(c==1)	  
	  	cout<<'\n';  
	  }
	// your code goes here
	return 0;
}