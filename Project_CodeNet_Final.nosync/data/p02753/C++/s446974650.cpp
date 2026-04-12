#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define REP(i,a,n) for(int (i)=(a); (i)<(int)(n); (i)++)
#define rep(i,n) REP(i,0,n)
#define vec vector 


int main(){
  vec<char> S(3);
  rep(i, 3) cin >> S.at(i);
  
  if(S.at(0) == S.at(1) && S.at(1) == S.at(2)){
    cout << "No";
  }else{
    cout << "Yes";
  }
}