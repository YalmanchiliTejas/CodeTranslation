#include<iostream>
using namespace std;
int n,m;
int data[16][16];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
void reversal(int r,int c)
{
  int tmp=data[r][c];
  if(data[r][c]==0)
    data[r][c]=1;
  else
    data[r][c]=0;
  for(int i=0;i<4;i++)
    if(r+dx[i]>=0&&r+dx[i]<n &&
       c+dy[i]>=0&&c+dy[i]<n )
      if(tmp==data[r+dx[i]][c+dy[i]])
	reversal(r+dx[i],c+dy[i]);
}
void rotate(int r,int c,int s)
{
  int tmp[16][16];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      tmp[i][j]=data[i][j];


  for(int j=r;j<r+s;j++)
    for(int k=c;k<c+s;k++)
      {
	//		cout<<j<<" "<<k<<"<= ";
	//	cout<<r+s-1-(k-c)<<" "<<c+(j-r)<<endl;
	tmp[j][k]=data[r+s-1-(k-c)][c+(j-r)];
	//	tmp[j][k]=data[c+s-1-(k-c)][r+s-1-(j-r)];
	//tmp[k][j]=data[r+s-1-(j-r)][c+s-1-(k-c)];
      }

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      data[i][j]=tmp[i][j];
  
}
int main()
{
  cin>>n>>m;
  
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin>>data[i][j];
  for(int i=0;i<m;i++)
    {
      int o;
      cin>>o;
      if(o==0)
	{
	  int r,c,s,a;
	  cin>>r>>c>>s>>a;
	  r--;
	  c--;
	  for(int j=a/90;j>0;j--)
	    {
	      rotate(r,c,s);
	    }
	}
      else if(o==1)
	{//reversal
	  int r,c,s;
	  cin>>r>>c>>s;
	  r--;
	  c--;
	  for(int j=r;j<r+s;j++)
	    for(int k=c;k<c+s;k++)
	      {
	      if(data[j][k]==0)
		data[j][k]=1;
	      else
		data[j][k]=0;
	      }
	}
      else if(o==2)
	{//L_shift
	  int r;
	  cin>>r;
	  r--;
	  int tmp=data[r][0];
	  for(int i=0;i<n-1;i++)
	    data[r][i]=data[r][i+1];
	  data[r][n-1]=tmp;
	}
      else if(o==3)
	{//R_shift
	  int r;
	  cin>>r;
	  r--;
	  int tmp=data[r][n-1];
	  for(int i=n-1;i>0;i--)
	    data[r][i]=data[r][i-1];
	  data[r][0]=tmp;
	}
      else if(o==4)
	{
	  int r,c;
	  cin>>r>>c;
	  r--;c--;
	  reversal(r,c);
	}
      
    }
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      {
	cout<<data[i][j];
	if(j!=n-1)
	  cout<<" ";
	else
	  cout<<endl;
      }
}