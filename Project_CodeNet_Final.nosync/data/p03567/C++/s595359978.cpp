#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
  string S;
  cin>>S;
  int a=S.size();
  bool b=false;
  rep(i,a){
      if(i!=0){
          if(S[i]=='C'&&S[i-1]=='A'){
              b=true;
              break;
          }
      }
  }
  if(b==true){
      cout<<"Yes"<<endl;
  }
  else{
      cout<<"No"<<endl;
  }
}
