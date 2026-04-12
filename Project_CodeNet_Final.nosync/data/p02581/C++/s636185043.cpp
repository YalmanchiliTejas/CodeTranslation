#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
template<class S, class T> inline S max_L(S a,T b){
  return a>=b?a:b;
}
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
inline void wt_L(int x){
  int s=0;
  int m=0;
  char f[10];
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
int A[6000];
int arr[2000][3];
int dp[2000][2000];
int mx;
int mx1[2000];
int bf[2000][2000];
int bmx;
int bmx1[2000];
void change(int i, int j, int v){
  {
    auto Lj4PdHRW = (v);
    chmax(dp[i][j], Lj4PdHRW);
    chmax(dp[j][i], Lj4PdHRW);
    chmax(mx1[i], Lj4PdHRW);
    chmax(mx1[j], Lj4PdHRW);
    chmax(mx, Lj4PdHRW);
  }
}
int main(){
  int i, k;
  int a[3];
  int x;
  int y;
  int z;
  int res = 0;
  int ad = 0;
  rd(N);
  {
    int KL2GvlyY;
    for(KL2GvlyY=(0);KL2GvlyY<(3*N);KL2GvlyY++){
      rd(A[KL2GvlyY]);A[KL2GvlyY] += (-1);
    }
  }
  {
    auto cTE1_r3A = (A[0]);
    auto RZTsC2BF = ( A[1]);
    auto FmcKpFmN = ( A[3*N-1]);
    x = cTE1_r3A;
    y = RZTsC2BF;
    z = FmcKpFmN;
  }
  for(i=(0);i<(N);i++){
    mx1[i] = -1073709056;
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      dp[i][j] = -1073709056;
    }
  }
  change(x, y, 0);
  for(k=(0);k<(N-1);k++){
    int j;
    for(i=(0);i<(3);i++){
      a[i] = A[3*k+2+i];
    }
    sort(a, a+3);
    if(a[0]==a[2]){
      ad++;
      continue;
    }
    if(a[1]==a[2]){
      swap(a[0], a[2]);
    }
    bmx = mx;
    for(i=(0);i<(N);i++){
      bmx1[i] = mx1[i];
    }
    for(i=(0);i<(N);i++){
      bf[i][a[0]] = dp[i][a[0]];
    }
    for(i=(0);i<(3);i++){
      bf[a[i]][a[i]] = dp[a[i]][a[i]];
    }
    for(j=(0);j<(3);j++){
      for(i=(0);i<(N);i++){
        change(a[j], i, bmx1[i]);
      }
    }
    for(i=(0);i<(3);i++){
      for(j=(i+1);j<(3);j++){
        change(a[i], a[j], bmx);
      }
    }
    if(a[0]==a[1]){
      for(i=(0);i<(N);i++){
        change(i, a[2], bf[i][a[0]] + 1);
      }
    }
    for(i=(0);i<(3);i++){
      change(a[(i+1)%3], a[(i+2)%3], bf[a[i]][a[i]] + 1);
    }
  }
  res =max_L(mx, dp[z][z] + 1);
  wt_L(res + ad);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200813-1 [beta]

// --- original code ---
// int N, A[6000];
// int arr[2000][3];
// int dp[2000][2000], mx, mx1[2000];
// int bf[2000][2000], bmx, bmx1[2000];
// 
// void change(int i, int j, int v){
//   (dp[i][j], dp[j][i], mx1[i], mx1[j], mx) >?= v;
// }
// 
// {
//   int a[3], x, y, z;
//   int res = 0, ad = 0;
//   rd(N,(A--)(3N));
// 
//   (x, y, z) = (A[0], A[1], A[3N-1]);
// 
//   rep(i,N) mx1[i] = -int_inf;
//   rep(i,N) rep(j,N) dp[i][j] = -int_inf;
//   change(x, y, 0);
//   rep(k,N-1){
//     rep(i,3) a[i] = A[3*k+2+i];
//     sort(a, a+3);
//     if(a[0]==a[2]) ad++, continue;
//     if(a[1]==a[2]) swap(a[0], a[2]);
// 
//     bmx = mx;
//     rep(i,N) bmx1[i] = mx1[i];
//     rep(i,N) bf[i][a[0]] = dp[i][a[0]];
//     rep(i,3) bf[a[i]][a[i]] = dp[a[i]][a[i]];
//     
//     rep(j,3) rep(i,N) change(a[j], i, bmx1[i]);
//     rep(i,3) rep(j,i+1,3) change(a[i], a[j], bmx);
//     if(a[0]==a[1]) rep(i,N) change(i, a[2], bf[i][a[0]] + 1);
//     rep(i,3) change(a[(i+1)%3], a[(i+2)%3], bf[a[i]][a[i]] + 1);
//   }
//   res = max(mx, dp[z][z] + 1);
//   wt(res + ad);
// }
