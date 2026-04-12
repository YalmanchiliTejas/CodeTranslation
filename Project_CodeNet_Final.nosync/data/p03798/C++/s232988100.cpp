#include <iostream>
#include <string>
using namespace std;

int main(){
  int n,i,j;
  string s;
  cin >> n;
  cin >> s;
  int a[n];
  bool flag;
  for(j=0;j<=3;j++){
    a[0]=j%2;
    a[1]=j/2;
    flag = false;
    for(i=1;i<n-1;i++){
      if(a[i]==1){
        if(s[i]=='o')a[i+1]=a[i-1];
        else a[i+1]=1^a[i-1];
      }else{
        if(s[i]=='o')a[i+1]=1^a[i-1];
        else a[i+1]=a[i-1];
      }
    }

    if(a[n-1]==1){
      if(s[n-1]=='o' && a[0]==a[n-2])flag = true;
      else if(s[n-1]=='x' && a[0]!=a[n-2])flag = true;
    }else{
      if(s[n-1]=='o' && a[0]!=a[n-2])flag = true;
      else if(s[n-1]=='x' && a[0]==a[n-2])flag = true;
    }
    bool f2=false;
    if(a[0]==1){
      if(s[0]=='o' && a[1]==a[n-1])f2 = true;
      else if(s[0]=='x' && a[1]!=a[n-1])f2=true;
    }else{
      if(s[0]=='o' && a[1]!=a[n-1])f2 = true;
      else if(s[0]=='x' && a[1]==a[n-1])f2=true;
    }
    if(flag && f2){
      for(i=0;i<n;i++){
        if(a[i]==1)cout << 'S';
        else cout << 'W';
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
