#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;
  int a[n+1]={};

  for(int i=0;i<=1;i++){
    for(int j=0;j<=1;j++){
      a[0]=i;
      a[1]=j;
      int flag1=0,flag2=0;
      for(int k=2;k<n;k++){
        if(a[k-1]==0&&s[k-1]=='o') a[k]=a[k-2];
        if(a[k-1]==0&&s[k-1]=='x') a[k]=a[k-2]^1;
        if(a[k-1]==1&&s[k-1]=='o') a[k]=a[k-2]^1;
        if(a[k-1]==1&&s[k-1]=='x') a[k]=a[k-2];
      }
      if(a[0]==0&&s[0]=='o'&&a[n-1]==a[1]) flag1=1;
      if(a[0]==0&&s[0]=='x'&&a[n-1]!=a[1]) flag1=1;
      if(a[0]==1&&s[0]=='o'&&a[n-1]!=a[1]) flag1=1;
      if(a[0]==1&&s[0]=='x'&&a[n-1]==a[1]) flag1=1;
      if(a[n-1]==0&&s[n-1]=='o'&&a[n-2]==a[0]) flag2=1;
      if(a[n-1]==0&&s[n-1]=='x'&&a[n-2]!=a[0]) flag2=1;
      if(a[n-1]==1&&s[n-1]=='o'&&a[n-2]!=a[0]) flag2=1;
      if(a[n-1]==1&&s[n-1]=='x'&&a[n-2]==a[0]) flag2=1;
      if(flag1&&flag2){
        for(int l=0;l<n;l++){
          if(a[l]) cout<<'W';
          else cout<<'S';
        }
        cout<<endl;
        return 0;
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}
