


#include "bits/stdc++.h"
#include <random>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef string ST;


#define REP(i,n) for(LL (i)=0;(i)<(n);(i)++)
#define ALL(v) v.begin(), v.end()
#define PRINTLN(v) for(auto (a): v )   cerr << a << endl
#define PRINTSP(v) for(auto (a): v ) {cerr << a << " ";} cerr << endl

vector<LL> P;
vector<LL> B;
LL N, X;
LL EB;
LL EP;
void recusive(LL level) {
  //cerr << EP+EB << " : " << EP << " : " << EB <<" : " << level << endl;
  if (level == 0) {
    EP++;
    return;
  }
  if (EB+EP < X) {        // まだ食べれる
    EB++;                 // バンを食べる
    if ((EB + EP) == X) {
      return;
    }
    //cerr << EP + EB << " a " << EP << " : " << EB << " : " << level << endl;
    if ((EP + EB + P[level - 1] + B[level - 1]) <= X) { // 一つ下のレベルを全部を食べてもOK？
      EP += P[level - 1];
      EB += B[level - 1];
      //cerr << EP + EB << " b " << EP << " : " << EB << " : " << level << endl;
    }
    else {
      recusive(level - 1);
    }

    if (EB + EP == X) {
      //cerr << EP + EB << " c " << EP << " : " << EB << " : " << level << endl;

      return;
    }
   
    EP++;
    if (EB + EP == X) {
      return;
    }
    if ((EP + EB + P[level - 1] + B[level - 1]) <= X) { // 一つレベルが下を食べてもOK？
      EP += P[level - 1];
      EB += B[level - 1];
    }
    else {
      recusive(level - 1);
    }
    if (EB + EP == X) {
      return;
    }
    EB++;
    if (EB + EP == X) {
      return;
    }
  }
}


void func() {
  cin >> N >> X;
  
  //N = 49;
  //X = 1837933630796584;
  //cerr << N << endl;
  //cerr << X << endl;


  P.resize(N+1);
  B.resize(N+1);
  P[0] = 1;
  B[0] = 0;
  for (LL i = 1; i <= N; ++i) {
    P[i] = P[i - 1] * 2 + 1;
    B[i] = B[i - 1] * 2 + 2;
  }

  for (LL i = 0; i <= N; ++i) {
    //cerr << i << " : " << P[i] << " : " << B[i] << " : " << B[i]+P[i] << endl;
  }
  EP = 0;
  EB = 0;
  recusive(N);
  cout << EP;
}








#ifdef CALC_TIME 
#include <windows.h>
int main()
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  LARGE_INTEGER start, end;
  QueryPerformanceCounter(&start);
  // 何かの処理
  func();
  QueryPerformanceCounter(&end);
  double time = static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
  fprintf(stderr, "\n%lf[ms]\n", time);
  return 0;
}
#else 
int main()
{
  func();
  return 0;
}
#endif



