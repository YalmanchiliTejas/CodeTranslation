#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<cmath>
#include<cstring>
using namespace std;
char s[1000][9];
int a[1000][4],b[1000],n;
int fi(int p,int i){
  static char t[4][4][9]={
    {{"0xxxxxxx"},{},{},{}},
    {{"110yyyyx"},{"10xxxxxx"},{},{}},
    {{"1110yyyy"},{"10yxxxxx"},{"10xxxxxx"},{}},
    {{"11110yyy"},{"10yyxxxx"},{"10xxxxxx"},{"10xxxxxx"}}
  };
  int j,k;
  int xct=0,yct=0,yfl=1;
  for(j=0;j<i+1;++j){
    for(k=0;k<8;++k){
      if(0){
      }else if(t[i][j][k]=='0'){
	if(s[p+j][k]=='1'){
	  break;
	}
      }else if(t[i][j][k]=='1'){
	if(s[p+j][k]=='0'){
	  break;
	}
      }else if(t[i][j][k]=='y'){
	if(0){
	}else if(s[p+j][k]=='1'){
	  yfl=0;
	}else if(s[p+j][k]=='x'){
	  ++yct;
	}
      }else if(t[i][j][k]=='x'){
	if(s[p+j][k]=='x'){
	  ++xct;
	}
      }
    }
    if(k<8)
      break;
  }
  if(j>=i+1){
    if(i&&yfl){
      if(yct){
	return (1ll<<xct)*((1ll<<yct)-1)%1000000;
      }
    }else{
      return (1ll<<xct)*(1ll<<yct)%1000000;
    }
  }
  return 0;
}
int fj(int p){
  int i;
  int sm=0;
  if(p==n){
    sm=1;
  }else{
    if(b[p]>=0){
      sm=b[p];
    }else{
      for(i=0;i<min(4,n-p);++i){
	if(a[p][i])
	  sm=(sm+(long long)a[p][i]*fj(p+i+1))%1000000;
      }
      b[p]=sm;
    }
  }
  return sm;
}
int main(){
  int i,j;
  while(cin>>n,n){
    for(i=0;i<n;++i)
      cin>>s[i];
    for(i=0;i<4;++i)
      for(j=0;j<1000-i;++j)
	a[j][i]=fi(j,i);
    memset(b,-1,sizeof(b));
    cout<<fj(0)<<endl;
  }
  return 0;
}