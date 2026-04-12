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
inline void rd(int &x){
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
template<class S, class T> inline S chmax(S &a, T b){
  if(a<b){
    a=b;
  }
  return a;
}
int N;
int A[200000];
long long dp[3][200000+1];
int main(){
  int i, k;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(k=(0);k<(3);k++){
    int i;
    for(i=(0);i<(N+1);i++){
      dp[k][i] = -4611686016279904256LL;
    }
  }
  for(i=(0);i<(N);i++){
    for(k=(1);k<(3);k++){
      chmax(dp[k][i+1], dp[k-1][i]);
    }
    for(k=(0);k<(3);k++){
      if(i>0){
        chmax(dp[k][i+1], dp[k][i-1]+ A[i]);
      }
      else{
        chmax(dp[k][i+1], -4611686016279904256LL+ A[i]);
      }
    }
    if(i==0){
      chmax(dp[0][i+1], A[i]);
    }
    if(i==1){
      chmax(dp[1][i+1], A[i]);
    }
    if(i==2){
      chmax(dp[2][i+1], A[i]);
    }
  }
  if(N%2==0){
    wt_L(dp[1][N]);
    wt_L('\n');
  }
  else{
    wt_L(dp[2][N]);
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20200412-1

// --- original code ---
// int N, A[2d5];
// 
// ll dp[3][2d5+1];
// {
//   rd(N,A(N));
//   rep(k,3) rep(i,N+1) dp[k][i] = -ll_inf;
//   rep(i,N){
//     rep(k,1,3) dp[k][i+1] >?= dp[k-1][i];
//     rep(k,3) dp[k][i+1] >?= if[i>0, dp[k][i-1], -ll_inf] + A[i];
//     if(i==0) dp[0][i+1] >?= A[i];
//     if(i==1) dp[1][i+1] >?= A[i];
//     if(i==2) dp[2][i+1] >?= A[i];
//   }
// //  rep(i,N+1) wt(i, dp[0][i], dp[1][i], dp[2][i]);
//   wt(if[N%2==0, dp[1][N], dp[2][N]]);
// }
