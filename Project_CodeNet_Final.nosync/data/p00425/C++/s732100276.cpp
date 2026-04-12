#include<iostream>
using namespace std;
int main(){
  int a[10001][7];
  for(int i=0;i<7;i++)a[0][i]=i;
  int n;
  while(cin>>n){
    if(n==0)return 0;
  string in;
  for(int i=1;i<=n;i++){
    cin>>in;
    for(int j=1;j<7;j++){
      a[i][j]=a[i-1][j];
    }
    if(in=="North"){
      a[i][1]=a[i-1][2];
      a[i][2]=a[i-1][6];
      a[i][5]=a[i-1][1];
      a[i][6]=a[i-1][5];
    }
    if(in=="East"){
      a[i][1]=a[i-1][4];
      a[i][3]=a[i-1][1];
      a[i][4]=a[i-1][6];
      a[i][6]=a[i-1][3];
    }
 if(in=="West"){
      a[i][1]=a[i-1][3];
      a[i][3]=a[i-1][6];
      a[i][4]=a[i-1][1];
      a[i][6]=a[i-1][4];
    }
 if(in=="South"){
      a[i][1]=a[i-1][5];
      a[i][2]=a[i-1][1];
      a[i][5]=a[i-1][6];
      a[i][6]=a[i-1][2];
    }
 if(in=="Right"){
      a[i][2]=a[i-1][3];
      a[i][3]=a[i-1][5];
      a[i][4]=a[i-1][2];
      a[i][5]=a[i-1][4];
    }
 if(in=="Left"){
      a[i][2]=a[i-1][4];
      a[i][3]=a[i-1][2];
      a[i][4]=a[i-1][5];
      a[i][5]=a[i-1][3];
    }
  }int sum=0;
  for(int i=0;i<=n;i++){
    sum+=a[i][1];
  }
  cout<<sum<<endl;

  }
}