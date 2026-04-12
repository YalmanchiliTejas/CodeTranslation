#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }

int main(){
  int N; cin>>N;
  int h[N]; CINA(h,N);
  int high = 0;
  int r = 0;
  REP(i,N){
    if(h[i]>=high){ high = h[i]; ++r;}
  }
  cout << r << "\n";
}