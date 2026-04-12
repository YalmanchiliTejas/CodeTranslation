#include <iostream>
#include <ios>
#include <iomanip>
using namespace std;

int main(void){
  int n;
  while(1){
    cin>>n;
    if(n==0)break;

    int square[n][n];
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        square[i][j]=0;
      }
    }
    int x=n/2;
    int y=n/2+1;
    square[y][x]=1;
    for(int i=2;i<=n*n;i++){
      x=(x+1)%n;
      y=(y+1)%n;
      while(square[y][x]!=0){
        x=(x+n-1)%n;
        y=(y+1)%n;
      }
      square[y][x]=i;
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<right<<setw(4)<<square[i][j];
      }
      cout<<endl;
    }
  }
  return 0;
}

