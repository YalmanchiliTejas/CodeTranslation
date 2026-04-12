#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;

int64_t f(int64_t L){
  if(L==0){return 1;}
  return 2*f(L-1)+3;
}
int64_t fp(int64_t L){
  if(L==0){return 1;}
  return 1+2*fp(L-1);
}
int64_t s(int64_t L,int64_t X){
  if(L==0){return 1;}
  if(X>=2+2*f(L-1)){return 2*fp(L-1)+1;}
  else if(X>2+f(L-1)){return s(L-1,X-2-f(L-1))+1+fp(L-1);}
  else if(X>1+f(L-1)){return 1+fp(L-1);}
  else if(X>1){return s(L-1,X-1);}
  else {return 0;}
}
int main() {
  int64_t N,X;
  cin>>N>>X;
  cout<<s(N,X)<<endl;
  return 0;  
}