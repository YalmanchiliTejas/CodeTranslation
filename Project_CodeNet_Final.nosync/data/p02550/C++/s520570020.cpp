#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline int my_getchar_unlocked(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s == e && e == 1048576){
    e = fread_unlocked(buf, 1, 1048576, stdin);
    s = 0;
  }
  if(s == e){
    return EOF;
  }
  return buf[s++];
}
inline void rd(long long &x){
  int k;
  int m=0;
  x=0;
  for(;;){
    k = my_getchar_unlocked();
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
    k = my_getchar_unlocked();
    if(k<'0'||k>'9'){
      break;
    }
    x=x*10+k-'0';
  }
  if(m){
    x=-x;
  }
}
struct MY_WRITER{
  char buf[1048576];
  int s;
  int e;
  MY_WRITER(){
    s = 0;
    e = 1048576;
  }
  ~MY_WRITER(){
    if(s){
      fwrite_unlocked(buf, 1, s, stdout);
    }
  }
}
;
MY_WRITER MY_WRITER_VAR;
void my_putchar_unlocked(int a){
  if(MY_WRITER_VAR.s == MY_WRITER_VAR.e){
    fwrite_unlocked(MY_WRITER_VAR.buf, 1, MY_WRITER_VAR.s, stdout);
    MY_WRITER_VAR.s = 0;
  }
  MY_WRITER_VAR.buf[MY_WRITER_VAR.s++] = a;
}
inline void wt_L(char a){
  my_putchar_unlocked(a);
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
    my_putchar_unlocked('-');
  }
  while(s--){
    my_putchar_unlocked(f[s]+'0');
  }
}
long long chk[200000+1];
long long sm[200000+1];
int getnext(long long A, long long M){
  return (A*A) % M;
}
int main(){
  long long N;
  rd(N);
  long long X;
  rd(X);
  long long M;
  rd(M);
  long long ad;
  long long res = 0;
  long long i;
  long long j;
  long long k;
  long long r;
  long long d;
  for(i=(0);i<(200000+1);i++){
    chk[i] = -1;
  }
  for(i=(0);i<(N);i++){
    res += X;
    if(i <= 200000){
      sm[i] = res;
    }
    if(chk[X] != -1){
      k = i - chk[X];
      r = (N-1) - i;
      d = r / k;
      if(d > 0){
        res += d * (sm[i] - sm[chk[X]]);
        i += d * k;
      }
    }
    else{
      chk[X] = i;
    }
    X = getnext(X, M);
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200916-1

// --- original code ---
// ll chk[2d5+1];
// ll sm[2d5+1];
// 
// int getnext(ll A, ll M){
//   return (A*A) % M;
// }
// 
// {
//   ll @N, @X, @M, ad, res = 0;
//   ll i, j, k, r, d;
//   rep(i,2d5+1) chk[i] = -1;
// 
//   rep(i,N){
//     res += X;
//     if(i <= 2d5) sm[i] = res;
//     if(chk[X] != -1){
//       k = i - chk[X];
//       r = (N-1) - i;
//       d = r / k;
//       if(d > 0){
//         res += d * (sm[i] - sm[chk[X]]);
//         i += d * k;
//       }
//     } else {
//       chk[X] = i;
//     }
//     X = getnext(X, M);
//   }
// 
//   wt(res);
// }
