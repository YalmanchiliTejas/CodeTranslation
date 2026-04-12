#include "bits/stdc++.h"
#define _USE_MATH_DEFINES
#include <math.h>
 
using namespace std;
 
using LL = long long;
using VLL = std::vector<LL>;
using VVLL = std::vector<VLL>;
using VVVLL = std::vector<VVLL>;
using LD = long double;
using VLD = std::vector<LD>;
using VVLD = std::vector<VLD>;
using VVVLD = std::vector<VVLD>;
 
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }

#define REP(i,n) for(LL (i)=0;(i)<(n);(i)++)
#define ALL(v) v.begin(), v.end()
#define PRINTLN(v) {LL i=0; for(auto (a): v ){   cerr <<i << " : "<<  a << endl; i++;}}
#define PRINTSP(v) for(auto (a): v ) {cerr << a << " ";} cerr << endl
#define cmax(a,b) {if(a<b){a=b;}}
#define cmin(a,b) {if(a>b){a=b;}}
#define EACH(a,A) for(auto a: A)
//#define cmax(a,b) a = (a>b ? a:b)
//#define cmin(a,b) a = (a<b ? a:b) 
void func(){
  LL N,M;
  cin >> N>>M;
  VVLL A;
  A.resize(N);

  REP(i,M){
    LL a,b;
    cin >>a>>b;
    a--;
    b--;
    A[a].push_back(b);
    A[b].push_back(a);
  }
  REP(i,N){
    sort(ALL(A[i]));
  }
 
  VLL P;
  REP(i,N){
    P.push_back(i);
  }

  LL cnt=0;
  do{
    if(P[0]!=0){
      continue;
    }
    bool isConnect=true;
    REP(i,N-1){
      LL a = P[i];
      LL b = P[i+1];
      if(binary_search(ALL(A[a]),b)==false){
        isConnect = false;
        break;
      }
    }
    if(isConnect){
      //PRINTSP(P);
      cnt++;
    }
  }while(next_permutation(ALL(P)));
  cout << cnt;
} 
int main()
{
  func();
  return 0;
}
 