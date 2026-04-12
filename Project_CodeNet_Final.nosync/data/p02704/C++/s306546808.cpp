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
inline void rd(unsigned long long &x){
  int k;
  x=0;
  for(;;){
    k = my_getchar_unlocked();
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
inline void wt_L(unsigned long long x){
  int s=0;
  char f[21];
  while(x){
    f[s++]=x%10;
    x/=10;
  }
  if(!s){
    f[s++]=0;
  }
  while(s--){
    my_putchar_unlocked(f[s]+'0');
  }
}
int N;
int S[500];
int T[500];
unsigned long long U[500];
unsigned long long V[500];
unsigned long long res[500][500];
int rtyp[500];
int ctyp[500];
int rval[500];
int cval[500];
int tmp[500][500];
int fs;
int f[500];
int solve(int bt){
  int i;
  int r0 = 0;
  int r1 = 0;
  int c0 = 0;
  int c1 = 0;
  int x;
  int y;
  int cx;
  int cy;
  int iy;
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      tmp[i][j] = -1;
    }
  }
  for(i=(0);i<(N);i++){
    rtyp[i] = S[i];
    ctyp[i] = T[i];
    rval[i] = (U[i] >> bt) & 1;
    cval[i] = (V[i] >> bt) & 1;
  }
  for(i=(0);i<(N);i++){
    if(rtyp[i]==0 && rval[i]==1){
      int j;
      for(j=(0);j<(N);j++){
        if(tmp[i][j]==0){
          return 0;
        }
      }
      for(j=(0);j<(N);j++){
        tmp[i][j] = 1;
      }
      r1 = 1;
    }
  }
  for(i=(0);i<(N);i++){
    if(rtyp[i]==1 && rval[i]==0){
      int j;
      for(j=(0);j<(N);j++){
        if(tmp[i][j]==1){
          return 0;
        }
      }
      for(j=(0);j<(N);j++){
        tmp[i][j] = 0;
      }
      r0 = 1;
    }
  }
  for(i=(0);i<(N);i++){
    if(ctyp[i]==0 && cval[i]==1){
      int j;
      for(j=(0);j<(N);j++){
        if(tmp[i][j]==0){
          return 0;
        }
      }
      for(j=(0);j<(N);j++){
        tmp[j][i] = 1;
      }
      c1 = 1;
    }
  }
  for(i=(0);i<(N);i++){
    if(ctyp[i]==1 && cval[i]==0){
      int j;
      for(j=(0);j<(N);j++){
        if(tmp[j][i]==1){
          return 0;
        }
      }
      for(j=(0);j<(N);j++){
        tmp[j][i] = 0;
      }
      c0 = 1;
    }
  }
  if(r0+r1==1 && c0+c1==0){
    cx = cy = 0;
    for(i=(0);i<(N);i++){
      if(rval[i]==0){
        cx++;
      }
      else{
        cy++;
      }
    }
    if(cx && cy){
      r0 = r1 = 1;
    }
  }
  if(r0+r1==0 && c0+c1==1){
    cx = cy = 0;
    for(i=(0);i<(N);i++){
      if(cval[i]==0){
        cx++;
      }
      else{
        cy++;
      }
    }
    if(cx && cy){
      c0 = c1 = 1;
    }
  }
  if(r0 && c0){
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        if(tmp[i][j]==-1){
          tmp[i][j] = 1;
        }
      }
    }
  }
  else if(r1 && c1){
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        if(tmp[i][j]==-1){
          tmp[i][j] = 0;
        }
      }
    }
  }
  else if(r0 && r1){
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        tmp[i][j] = rval[i];
      }
    }
  }
  else if(c0 && c1){
    for(i=(0);i<(N);i++){
      int j;
      for(j=(0);j<(N);j++){
        tmp[i][j] = cval[j];
      }
    }
  }
  else if(r0 || r1){
    if(r0){
      x =0;
    }
    else{
      x =1;
    }
    y = 1 - x;
    cx = cy = 0;
    for(i=(0);i<(N);i++){
      if(cval[i]==x){
        cx++;
      }
      else{
        cy++;
      }
    }
    fs = 0;
    for(i=(0);i<(N);i++){
      if(rtyp[i]==rval[i]){
        f[fs++] = i;
      }
    }
    if(cx){
      for(i=(0);i<(N);i++){
        int j;
        for(j=(0);j<(N);j++){
          if(tmp[i][j]==-1){
            tmp[i][j] = cval[j];
          }
        }
      }
    }
    else if(fs >= 2){
      for(i=(0);i<(N);i++){
        int j;
        for(j=(0);j<(N);j++){
          tmp[i][j] = x;
        }
      }
      for(i=(0);i<(N);i++){
        tmp[f[i%2]][i] = y;
      }
    }
    else{
      return 0;
    }
  }
  else if(c0 || c1){
    if(c0){
      x =0;
    }
    else{
      x =1;
    }
    y = 1 - x;
    cx = cy = 0;
    for(i=(0);i<(N);i++){
      if(rval[i]==x){
        cx++;
      }
      else{
        cy++;
      }
    }
    fs = 0;
    for(i=(0);i<(N);i++){
      if(ctyp[i]==cval[i]){
        f[fs++] = i;
      }
    }
    if(cx){
      for(i=(0);i<(N);i++){
        int j;
        for(j=(0);j<(N);j++){
          if(tmp[i][j]==-1){
            tmp[i][j] = rval[i];
          }
        }
      }
    }
    else if(fs >= 2){
      for(i=(0);i<(N);i++){
        int j;
        for(j=(0);j<(N);j++){
          tmp[i][j] = x;
        }
      }
      for(i=(0);i<(N);i++){
        tmp[i][f[i%2]] = y;
      }
    }
    else{
      return 0;
    }
  }
  else{
    if(N==1){
      if(rval[0] != cval[0]){
        return 0;
      }
      tmp[0][0] = rval[0];
    }
    else{
      for(i=(0);i<(N);i++){
        int j;
        for(j=(0);j<(N);j++){
          tmp[i][j] = (i+j) % 2;
        }
      }
    }
  }
  for(i=(0);i<(N);i++){
    int j;
    for(j=(0);j<(N);j++){
      if(tmp[i][j]==1){
        res[i][j] |= (1ULL << bt);
      }
    }
  }
  return 1;
}
int main(){
  int i;
  rd(N);
  {
    int FBBe8PkL;
    for(FBBe8PkL=(0);FBBe8PkL<(N);FBBe8PkL++){
      rd(S[FBBe8PkL]);
    }
  }
  {
    int Ee8EXgVm;
    for(Ee8EXgVm=(0);Ee8EXgVm<(N);Ee8EXgVm++){
      rd(T[Ee8EXgVm]);
    }
  }
  {
    int o0VCpjj8;
    for(o0VCpjj8=(0);o0VCpjj8<(N);o0VCpjj8++){
      rd(U[o0VCpjj8]);
    }
  }
  {
    int vzsjNTAU;
    for(vzsjNTAU=(0);vzsjNTAU<(N);vzsjNTAU++){
      rd(V[vzsjNTAU]);
    }
  }
  for(i=(0);i<(64);i++){
    if(!solve(i)){
      wt_L(-1);
      wt_L('\n');
      return 0;
    }
  }
  {
    int NjXMiQ70;
    int CnS5KYSU;
    for(NjXMiQ70=(0);NjXMiQ70<(N);NjXMiQ70++){
      if(N==0){
        wt_L('\n');
      }
      else{
        for(CnS5KYSU=(0);CnS5KYSU<(N-1);CnS5KYSU++){
          wt_L(res[NjXMiQ70][CnS5KYSU]);
          wt_L(' ');
        }
        wt_L(res[NjXMiQ70][CnS5KYSU]);
        wt_L('\n');
      }
    }
  }
  return 0;
}
// cLay varsion 20200419-1

// --- original code ---
// int N;
// int S[500], T[500];
// ull U[500], V[500];
// 
// ull res[500][500];
// 
// int rtyp[500], ctyp[500], rval[500], cval[500];
// int tmp[500][500];
// int fs, f[500];
// 
// int solve(int bt){
//   int r0 = 0, r1 = 0, c0 = 0, c1 = 0;
//   int x, y, cx, cy, iy;
// 
//   rep(i,N) rep(j,N) tmp[i][j] = -1;
// 
//   rep(i,N){
//     rtyp[i] = S[i];
//     ctyp[i] = T[i];
//     rval[i] = (U[i] >> bt) & 1;
//     cval[i] = (V[i] >> bt) & 1;
//   }
// 
//   rep(i,N) if(rtyp[i]==0 && rval[i]==1){
//     rep(j,N) if(tmp[i][j]==0) return 0;
//     rep(j,N) tmp[i][j] = 1;
//     r1 = 1;
//   }
//   rep(i,N) if(rtyp[i]==1 && rval[i]==0){
//     rep(j,N) if(tmp[i][j]==1) return 0;
//     rep(j,N) tmp[i][j] = 0;
//     r0 = 1;
//   }
// 
//   rep(i,N) if(ctyp[i]==0 && cval[i]==1){
//     rep(j,N) if(tmp[i][j]==0) return 0;
//     rep(j,N) tmp[j][i] = 1;
//     c1 = 1;
//   }
//   rep(i,N) if(ctyp[i]==1 && cval[i]==0){
//     rep(j,N) if(tmp[j][i]==1) return 0;
//     rep(j,N) tmp[j][i] = 0;
//     c0 = 1;
//   }
// 
// //  wt(bt,r0,r1,c0,c1);
// 
//   if(r0+r1==1 && c0+c1==0){
//     cx = cy = 0;
//     rep(i,N) if[rval[i]==0, cx, cy]++;
//     if(cx && cy) r0 = r1 = 1;
//   }
//   if(r0+r1==0 && c0+c1==1){
//     cx = cy = 0;
//     rep(i,N) if[cval[i]==0, cx, cy]++;
//     if(cx && cy) c0 = c1 = 1;
//   }
// 
//   if(r0 && c0){
//     rep(i,N) rep(j,N) if(tmp[i][j]==-1) tmp[i][j] = 1;
//   } else if(r1 && c1) {
//     rep(i,N) rep(j,N) if(tmp[i][j]==-1) tmp[i][j] = 0;
//   } else if(r0 && r1) {
//     rep(i,N) rep(j,N) tmp[i][j] = rval[i];
//   } else if(c0 && c1) {
//     rep(i,N) rep(j,N) tmp[i][j] = cval[j];
//   } else if(r0 || r1) {
//     x = if[r0, 0, 1];
//     y = 1 - x;
// 
//     cx = cy = 0;
//     rep(i,N) if[cval[i]==x, cx, cy]++;
// 
//     fs = 0;
//     rep(i,N) if(rtyp[i]==rval[i]) f[fs++] = i;
// 
//     if(cx){
//       rep(i,N) rep(j,N) if(tmp[i][j]==-1) tmp[i][j] = cval[j];
//     } else if(fs >= 2) {
//       rep(i,N) rep(j,N) tmp[i][j] = x;
//       rep(i,N) tmp[f[i%2]][i] = y;
//     } else {
//       return 0;
//     }
//   } else if(c0 || c1) {
//     x = if[c0, 0, 1];
//     y = 1 - x;
// 
//     cx = cy = 0;
//     rep(i,N) if[rval[i]==x, cx, cy]++;
// 
//     fs = 0;
//     rep(i,N) if(ctyp[i]==cval[i]) f[fs++] = i;
// 
//     if(cx){
//       rep(i,N) rep(j,N) if(tmp[i][j]==-1) tmp[i][j] = rval[i];
//     } else if(fs >= 2) {
//       rep(i,N) rep(j,N) tmp[i][j] = x;
//       rep(i,N) tmp[i][f[i%2]] = y;
//     } else {
//       return 0;
//     }
//   } else {
//     if(N==1){
//       if(rval[0] != cval[0]) return 0;
//       tmp[0][0] = rval[0];
//     } else {
//       rep(i,N) rep(j,N) tmp[i][j] = (i+j) % 2;
//     }
//   }
// 
//   rep(i,N) rep(j,N) if(tmp[i][j]==1) res[i][j] |= (1ULL << bt);
//   return 1;
// }
// 
// {
//   rd(N,S(N),T(N),U(N),V(N));
//   rep(i,64) if(!solve(i)) wt(-1), return 0;
//   wt(res(N,N));
// }
