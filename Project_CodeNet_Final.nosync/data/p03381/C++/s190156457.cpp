
#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(int i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
#ifdef DEBUG
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int N, X[200000], x[200000];

int main(){
  scanf("%d", &N);
  REP(N){
    scanf("%d", &X[i]);
    x[i] = X[i];
  }
  sort(X, X+N);
  int meda = X[N/2-1], medb = X[N/2];
  REP(N){
    if(meda<x[i])printf("%d\n", meda);
    else printf("%d\n", medb);
  }
  return 0;
}

