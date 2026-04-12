#include<bits/stdc++.h>
using namespace std;

bool dp[17][1<<16];
int main(){
  int n,h[16],w[16];
  char r[3]={'R','G','B'};
  string c[4];
  cin>>n;
  for(int i=0;i<n;i++)cin>>h[i]>>w[i];
  for(int i=0;i<4;i++)cin>>c[i];

  int a1[16][7][7],o1[16][3][7][7]={};
  for(int i=0;i<n;i++)
    for(int j=0;j<7;j++)for(int k=0;k<7;k++)a1[i][j][k]=(1<<16)-1;
  
  for(int k=0;k<n;k++)
    for(int cl=0;cl<3;cl++)
      for(int y=-h[k]+1;y<4;y++)
	for(int x=-w[k]+1;x<4;x++){
	  for(int l=max(0,y);l<min(4,y+h[k]);l++)
	    for(int m=max(0,x);m<min(4,x+w[k]);m++){
	      int xx=l*4+m;
	      if(c[l][m]==r[cl])o1[k][cl][y+3][x+3]|=1<<xx;
	      if(!cl)a1[k][y+3][x+3]-=1<<xx;
	    }
	}
  
  dp[0][0]=1;
  for(int j=0;j<16;j++)
    for(int i=0;i<1<<16;i++)
      if(dp[j][i])
	for(int k=0;k<n;k++)
	  for(int cl=0;cl<3;cl++)
	    for(int y=-h[k]+1;y<4;y++)
	      for(int x=-w[k]+1;x<4;x++){
		int ni=(i&a1[k][y+3][x+3])|o1[k][cl][y+3][x+3];
		dp[j+1][ni]=1;
		if(ni==(1<<16)-1){cout<<j+1<<endl;return 0;}
	      }
}