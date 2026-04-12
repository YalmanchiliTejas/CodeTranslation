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
  chmax(dp[i][j], v);
  chmax(dp[j][i], v);
  chmax(mx1[i], v);
  chmax(mx1[j], v);
  chmax(mx, v);
}
int main(){
  int i, k;
  int a;
  int b;
  int c;
  int x;
  int y;
  int z;
  int block = 0;
  int res = 0;
  int ad = 0;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=(0);Lj4PdHRW<(3*N);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);A[Lj4PdHRW] += (-1);
    }
  }
  {
    auto e98WHCEY = (A[0]);
    auto cTE1_r3A = ( A[1]);
    auto RZTsC2BF = ( A[3*N-1]);
    x = e98WHCEY;
    y = cTE1_r3A;
    z = RZTsC2BF;
  }
  block = 0;
  for(i=(0);i<(N-1);i++){
    {
      int WYIGIcGE;
      for(WYIGIcGE=(0);WYIGIcGE<((2) + 1);WYIGIcGE++){
        arr[block][WYIGIcGE] = A[3*i+(WYIGIcGE - (0) + (2))];
      }
    }
    if(arr[block][0]==arr[block][1] && arr[block][1]==arr[block][2]){
      ad++;
      continue;
    }
    block++;
  }
  mx = -1073709056;
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
  for(k=(0);k<(block);k++){
    {
      auto jbtyPBGc = (arr[k][0]);
      auto ZIeRIny5 = ( arr[k][1]);
      auto iMWUTgY_ = ( arr[k][2]);
      a = jbtyPBGc;
      b = ZIeRIny5;
      c = iMWUTgY_;
    }
    if(b==c){
      swap(a, c);
    }
    if(a==c){
      swap(b, c);
    }
    bmx = mx;
    for(i=(0);i<(N);i++){
      bmx1[i] = mx1[i];
    }
    for(i=(0);i<(N);i++){
      bf[i][a] = dp[i][a];
    }
    bf[a][a] = dp[a][a];
    bf[b][b] = dp[b][b];
    bf[c][c] = dp[c][c];
    for(i=(0);i<(N);i++){
      change(a, i, bmx1[i]);
      change(b, i, bmx1[i]);
      change(c, i, bmx1[i]);
    }
    change(a, b, bmx);
    change(a, c, bmx);
    change(b, c, bmx);
    if(a==b){
      for(i=(0);i<(N);i++){
        change(i, c, bf[i][a] + 1);
      }
    }
    change(b, c, bf[a][a] + 1);
    change(a, c, bf[b][b] + 1);
    change(a, b, bf[c][c] + 1);
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
//   dp[i][j] >?= v;
//   dp[j][i] >?= v;
//   mx1[i] >?= v;
//   mx1[j] >?= v;
//   mx >?= v;
// }
// 
// {
//   int a, b, c, x, y, z, block = 0;
//   int res = 0, ad = 0;
//   rd(N,(A--)(3N));
// 
//   (x, y, z) = (A[0], A[1], A[3N-1]);
//   block = 0;
//   rep(i,N-1){
//     arr[block][0..2] = A[3*i+(2..4)];
//     if(arr[block][0]==arr[block][1]==arr[block][2]) ad++, continue;
//     block++;
//   }
// 
//   mx = -int_inf;
//   rep(i,N) mx1[i] = -int_inf;
//   rep(i,N) rep(j,N) dp[i][j] = -int_inf;
//   change(x, y, 0);
//   rep(k,block){
//     (a, b, c) = (arr[k][0], arr[k][1], arr[k][2]);
//     if(b==c) swap(a, c);
//     if(a==c) swap(b, c);
// 
//     bmx = mx;
//     rep(i,N) bmx1[i] = mx1[i];
//     rep(i,N) bf[i][a] = dp[i][a];
//     bf[a][a] = dp[a][a];
//     bf[b][b] = dp[b][b];
//     bf[c][c] = dp[c][c];
//     
//     rep(i,N){
//       change(a, i, bmx1[i]);
//       change(b, i, bmx1[i]);
//       change(c, i, bmx1[i]);
//     }
//     change(a, b, bmx);
//     change(a, c, bmx);
//     change(b, c, bmx);
//     if(a==b) rep(i,N) change(i, c, bf[i][a] + 1);
//     change(b, c, bf[a][a] + 1);
//     change(a, c, bf[b][b] + 1);
//     change(a, b, bf[c][c] + 1);
//   }
//   res = max(mx, dp[z][z] + 1);
//   wt(res + ad);
// }
