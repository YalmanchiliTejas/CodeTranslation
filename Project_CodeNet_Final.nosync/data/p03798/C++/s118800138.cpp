#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string S;
  cin >> N >> S;
  string ans="";
  char d1[2]={'S','W'};
  char dN[2]={'S','W'};
  for (int i=0;i<2;i++){
    for (int j=0;j<2;j++){
      string a="";
      a+=d1[i];
      if ((i==0&&S[0]=='o')||(i==1&&S[0]=='x')){
        a+=dN[j];
      }
      else {
        a+=dN[(j+1)%2];
      }
      for (int k=1;k<N-1;k++){
        if ((a[k]=='S'&&S[k]=='o')||(a[k]=='W'&&S[k]=='x')){
          a+=a[k-1];
        }
        else {
          if (a[k-1]=='S'){
            a+='W';
          }
          else {
            a+='S';
          }
        }
      }
      if (a[N-1]==dN[j]){
        if (((j==0&&S[N-1]=='o')||(j==1&&S[N-1]=='x'))&&a[0]==a[N-2]){
          ans=a;
        }
        else if (((j==0&&S[N-1]=='x')||(j==1&&S[N-1]=='o'))&&a[0]!=a[N-2]){
          ans=a;
        }
      }
    }
  }
  if (ans.size()>0){
    cout << ans << endl;
  }
  else {
    cout << -1 << endl;
  }
}