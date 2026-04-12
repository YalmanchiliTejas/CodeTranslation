#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
  int n,i,sp0,sp1;
  string s;
  cin >> n >> s;
  for (sp0=0;sp0<2;sp0++) for (sp1=0;sp1<2;sp1++){
    int sp[100010];
    sp[0]=sp0;
    sp[1]=sp1;
    for (i=1;i<=n;i++){
      if (sp[i]==1){
        if (s[i%n]=='o') sp[i+1]=sp[i-1];
        else sp[i+1]=1-sp[i-1];
      }else{
        if (s[i%n]=='o') sp[i+1]=1-sp[i-1];
        else sp[i+1]=sp[i-1];
      }
    }
    if (sp[0]==sp[n] && sp[1]==sp[n+1]){
      for (i=0;i<n;i++){
        if (sp[i]==1) cout << 'S';
        else cout << 'W';
      }
      cout << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}