#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
#define RAP(i, n) for(ll i=0;i<(n);i++)
#define FOR(i, a, b) for(ll i=(a);i<(b);i++)

int main(){
  string S;
  bool flag = false;
  cin >> S;
  for(ll i=1;i<3;i++){
      if(S[0]!=S[i]){
          flag=true;
      }
  }
  if(flag){
      cout << "Yes" << endl;
  }else{
      cout << "No" << endl;
  }
  
  return 0;
 
}
