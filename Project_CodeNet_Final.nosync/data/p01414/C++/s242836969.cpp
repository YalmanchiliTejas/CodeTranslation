#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int N;
  cin>>N;
  int H[16],W[16];
  for(int i=0;i<N;i++){
    cin>>H[i]>>W[i];
  }
  int g[4][4];
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      char c;
      cin>>c;
      g[i][j]=
	(c=='R')?1:
	(c=='G')?2:3;
    }
  }
  int dp[1<<16];
  fill(begin(dp),end(dp),99);
  dp[0]=0;
  for(int i=0;i<1<<16;i++){
    int cg[10][10]={};
    for(int j=0;j<4;j++){
      for(int k=0;k<4;k++){
	if(!(i>>j*4+k&1)){
	  cg[j+3][k+3]=g[j][k];
	}
      }
    }
    for(int j=0;j<N;j++){
      for(int k=0;k<7;k++){
	for(int l=0;l<7;l++){
	  bool c[4]={};
	  int nb=i;
	  for(int m=0;m<H[j];m++){
	    for(int n=0;n<W[j];n++){
	      int y=k+m;
	      int x=l+n;
	      c[cg[y][x]]=true;
	      if(3<=y&&y<=6&&3<=x&&x<=6){
		nb|=1<<(y-3)*4+x-3;
	      }
	    }
	  }
	  if(c[1]+c[2]+c[3]==1){
	    dp[nb]=min(dp[nb],dp[i]+1);
	  }
	}
      }
    }
  }
  cout<<dp[(1<<16)-1]<<endl;
}