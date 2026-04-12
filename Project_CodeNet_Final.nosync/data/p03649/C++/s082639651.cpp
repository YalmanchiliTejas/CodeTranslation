#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar_unlocked();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void rd(long long &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = getchar_unlocked();
    if(k=='-'){
      m=1;
      break;
    }
    if('0'<=k&&k<='9'){
      x=k-'0';
      break;
    }
  }
  for(;;){
    k = getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(long long x){
  int s=0;
  int m=0;
  char f[20];
  if(x<0){
    m=1;
    x=-x;
  }
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  if(m){
    putchar_unlocked('-');
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
int N;
long long A[50];
int main(){
  int i;
  int j;
  int fg;
  long long res = 0;
  long long t;
  long long s;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(;;){
    s = 0;
    for(i=(0);i<(N);i++){
      t = A[i] / N;
      s += t;
      A[i] -= t * (N+1);
    }
    if(s==0){
      break;
    }
    res += s;
    for(i=(0);i<(N);i++){
      A[i] += s;
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190921-1

// --- original code ---
// int N; ll A[50];
// {
//   int i, j, fg;
//   ll res = 0, t, s;
//   rd(N,A(N));
//   for(;;){
//     s = 0;
//     rep(i,N){
//       t = A[i] / N;
//       s += t;
//       A[i] -= t * (N+1);
//     }
//     if(s==0) break;
//     res += s;
//     rep(i,N) A[i] += s;
//   }
//   wt(res);
// }
