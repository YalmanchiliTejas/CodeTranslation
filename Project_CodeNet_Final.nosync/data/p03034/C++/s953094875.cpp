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
int d[100000];
int ds;
int dl;
int n;
int s[100000];
int main(){
  int i, j, k, x;
  long long res, tmp;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(S[Lj4PdHRW]);
    }
  }
  N--;
  ds = 1;
  d[0] = 1;
  res = 0;
  for(dl=0;dl<ds;dl++){
    n = N / d[dl];
    for(i=0;i<n;i++){
      s[i] = S[i*d[dl]];
    }
    s[n] = 0;
    for(x=1;x<n;x++){
      i = 0;
      j = n;
      tmp = 0;
      for(;;){
        i += x;
        j -= x;
        if(i==j || i+x > n || j-x < 0){
          break;
        }
        if(N%x==0 && i > j){
          break;
        }
        tmp += s[i] + s[j];
        chmax(res, tmp);
      }
    }
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190526-1

// --- original code ---
// int N, S[1d5];
// 
// int d[1d5], ds, dl;
// int n, s[1d5];
// {
//   int i, j, k, x;
//   ll res, tmp;
// 
//   rd(N, S(N));
//   N--;
// 
//   ds = 1;
//   d[0] = 1;
//   
//   res = 0;
// 
//   rep(dl,ds){
//     n = N / d[dl];
//     rep(i,n) s[i] = S[i*d[dl]];
//     s[n] = 0;
// 
//     rep(x,1,n){
//       i = 0;
//       j = n;
//       tmp = 0;
//       for(;;){
//         i += x;
//         j -= x;
//         if(i==j || i+x > n || j-x < 0) break;
//         if(N%x==0 && i > j) break;
//         tmp += s[i] + s[j];
//         res >?= tmp;
//       }
//     }
//   }
// 
//   wt(res);
// }
