#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
bool mem[12][12],cop[12][12],done[12][12];

int main(){
  int n;cin>>n;
  while(n--){
    lol(i,10)lol(j,10)cin>>mem[i][j];
    bool flag[10],tmp[10]={0};
    for(int p=1;p<=1024;p++){
      lol(i,10)flag[i]=tmp[i];
      lol(i,10)lol(j,10)cop[i][j]=mem[i][j];
      for(int k=0;k<10;k++){
	lol(i,10){
	  if(!flag[i])continue;
	  for(int j=max(0,i-1);j<=min(9,i+1);j++)cop[k][j]^=1;
	  cop[k+1][i]^=1;
	}
	lol(i,10)done[k][i]=flag[i];
	lol(i,10)flag[i]=cop[k][i];
      }
      bool na=false;
      lol(i,10)na|=flag[i];
      if(!na){
	lol(i,10){
	  lol(j,10){
	    if(j)cout<<" ";
	    cout<<done[i][j];
	  }
	  cout<<endl;
	}
	break;
      }
      for(int i=0;i<10;i++){
	int r=pow(2,i);
	if(p%r==0)tmp[i]^=1;
      }
    }
  }
  return 0;
}