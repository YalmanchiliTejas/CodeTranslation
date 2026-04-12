#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1000000007;
const int INF=1001001001;

int main() {
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int M=min(X,Y);
  int T=min(A*M+B*M,C*2*M);
  if(M==X){
    int s=Y-M;
    cout<<T+min(B*s,C*2*s)<<endl;
  }
  else{
    int s=X-M;
    cout<<T+min(A*s,C*2*s)<<endl;
  }
  return 0;  
}