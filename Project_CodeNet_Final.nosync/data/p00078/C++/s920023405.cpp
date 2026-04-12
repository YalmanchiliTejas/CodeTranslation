//05
#include<iostream>
#include<iomanip>

using namespace std;

int main(){
  for(int n;cin>>n,n;){
    int ms[15][15]={};
    int y=n/2+1,x=n/2;
    for(int i=1;i<=n*n-1;i++){
      ms[y][x]=i;
      y=(y+1)%n;
      x=(x+1)%n;
      while(ms[y][x]){
	y=(y+1)%n;
	x=(x+n-1)%n;
      }
    }
    ms[y][x]=n*n;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	cout<<setw(4)<<right<<ms[i][j];
      }
      cout<<endl;
    }
  }
  return 0;
}