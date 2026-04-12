#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
  int n;
  for(;cin>>n,n;)
    {
      int t[n][n];
      for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	  t[i][j]=0;
      t[(n/2)+1][n/2]=1;
      int x=(n/2)+2,y=n/2+1;
      int num=2;
      while(num<=(n*n))
	{
	  if(x<=n-1 && y<=n-1 && x>=0 && y>=0 && t[x][y]==0)
	    {
	      //	      cout<<"a"<<endl;
	      t[x][y]=num;
	      x=x+1;  
	      y=y+1;
	      num++;
	    }
	  else{
	    if(y>n-1)
	      {
		//		cout<<"c"<<endl;
		y=0;
	      }
	    if(y<0)
	      {
		//		cout<<"d"<<endl;
		y=n-1;
	      }
	    if(x>n-1)
	      {
		//		cout<<"e"<<endl;
		x=0;
	      }
	    

	    if(t[x][y]!=0)
	      {
		//		cout<<"b"<<endl;
		y=y-1;
		x=x+1;
	      }
	  }
	  //	  cout<<num<<" "<<x<<" "<<y <<endl;
	}
      
      for(int i=0;i<n;i++,cout<<endl)
	for(int j=0;j<n;j++)
	  printf("%4d",t[i][j]);

    }
}