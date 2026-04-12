#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S min_L(S a,T b){
  return a<=b?a:b;
}
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
inline void wt_L(int x){
  char f[10];
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
template<class S, class T> inline S chmin(S &a, T b){
  if(a>b){
    a=b;
  }
  return a;
}
int A;
int B;
int C;
int X;
int Y;
int main(){
  int k, res=1073709056;
  rd(A);
  rd(B);
  rd(C);
  rd(X);
  rd(Y);
  chmin(res, A * X + B * Y);
  k =min_L(X, Y);
  chmin(res, A * (X-k) + B * (Y-k) + 2*k * C);
  k =max_L(X, Y);
  chmin(res, 2*k * C);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190721-1

// --- original code ---
// int A, B, C, X, Y;
// {
//   int k, res = int_inf;
//   rd(A,B,C,X,Y);
// 
//   res <?= A * X + B * Y;
// 
//   k = min(X,Y);
//   res <?= A * (X-k) + B * (Y-k) + 2k * C;
// 
//   k = max(X,Y);
//   res <?= 2k * C;
// 
//   wt(res);
// }
