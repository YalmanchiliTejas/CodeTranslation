#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
#define INFTY 3400000000

int main(){
  int H,W;
  char temp;
  cin>>H>>W;
  bool A[10][10];
  for(int i=0;i<H;i++){
    for(int k=0;k<W;k++){
      cin>>temp;
      if(temp=='#') A[i][k]=true;
      else A[i][k]=false;
    }
  }
  bool flag=false;
  int pre=0,last=-1;
  for(int i=0;i<H;i++){
    for(int k=0;k<W;k++){
      if(A[i][k]==true){
        if(pre>k) flag=true;
        if(last!=-1 && last!=k-1) flag=true;
        last=k;
      }
    }
    pre=last;
    last=-1;
  }
  if(flag) cout<<"Impossible"<<endl;
  else cout<<"Possible"<<endl;
  
}
