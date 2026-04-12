#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main(){
  int n,x,y;
  while(cin>>n&&n){
    x=n/2;y=n/2+1;
    int m[n][n];
    memset(m,0,sizeof(m));
    for(int i=1;i<=n*n;++i){
      if(m[y][x]==0) m[y][x]=i;
      else{
	while(1){
	  x=(x+n-1)%n;y=(y+1)%n;
	  if(m[y][x]==0){
	    m[y][x]=i;break;
	  }
	}
      }
      x=(x+1)%n;y=(y+1)%n;
    }
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j) cout<<setw(4)<<right<<m[i][j];
      cout<<endl;
    }
  }
  return 0;
}