#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

int main(void)
{
  int h,w;
  cin>>h>>w;
  char a[110][110];
  bool check[110][110];
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      check[i][j]=true;
    }
  }
  bool check2[110];
  for(int i=0;i<h;i++){
    check2[i]=true;
  }


  bool flag;
  for(int i=0;i<h;i++){
    flag=true; 
    for(int j=0;j<w;j++){
      if(a[i][j]=='#')
	flag=false;
      if(flag==false) break;
    }
    if(flag){
      for(int k=0;k<w;k++){
	check[i][k]=false;
	check2[i]=false;
      } 
    }
  }
  for(int i=0;i<w;i++){
    flag=true; 
    for(int j=0;j<h;j++){
      if(a[j][i]=='#')
	flag=false;
      if(flag==false) break;
    }
    if(flag){
      for(int k=0;k<h;k++){
	check[k][i]=false;
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(check[i][j]){
	cout<<a[i][j];
      }
    }
    if(check2[i]){
      cout<<endl;
    }
  }
  return 0;
}
