#include<bits/stdc++.h>
using namespace std;
inline void rd(int &x){
  int k, m=0;
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
  char f[20];
  int m=0, s=0;
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int S[100000];
int main(){
  int i, j, x;
  long long res, tmp;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(S[Lj4PdHRW]);
    }
  }
  N--;
  res = 0;
  for(x=1;x<N;x++){
    i = 0;
    j = N;
    tmp = 0;
    for(;;){
      i += x;
      j -= x;
      if(i==j || i+x > N || j-x < 0){
        break;
      }
      if(N%x==0 && i > j){
        break;
      }
      tmp += S[i] + S[j];
      chmax(res, tmp);
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190526-1

// --- original code ---
// int N, S[1d5];
// {
//   int i, j, x;
//   ll res, tmp;
// 
//   rd(N, S(N));
//   N--;
// 
//   res = 0;
//   rep(x,1,N){
//     i = 0;
//     j = N;
//     tmp = 0;
//     for(;;){
//       i += x;
//       j -= x;
//       if(i==j || i+x > N || j-x < 0) break;
//       if(N%x==0 && i > j) break;
//       tmp += S[i] + S[j];
//       res >?= tmp;
//     }
//   }
// 
//   wt(res);
// }
