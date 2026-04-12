#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define BITBOOL(x,a) (((x)>>(a))&1)
int main(void){
  string S; int A=0;
  cin >> S;
  FOR(i,0,3) if(S[i]=='A') A++;
  if(A==0 || A==3) {cout << "No"; return 0;}
  else cout << "Yes";
  return 0;
}