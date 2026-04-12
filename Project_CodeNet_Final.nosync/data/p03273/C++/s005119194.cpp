#pragma GCC optimize ("Ofast")
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
inline void rd(char &c){
  int i;
  for(;;){
    i = getchar_unlocked();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c = i;
}
inline int rd(char c[]){
  int i, sz=0;
  for(;;){
    i = getchar_unlocked();
    if(i!=' '&&i!='\n'&&i!='\r'&&i!='\t'&&i!=EOF){
      break;
    }
  }
  c[sz++] = i;
  for(;;){
    i = getchar_unlocked();
    if(i==' '||i=='\n'||i=='\r'||i=='\t'||i==EOF){
      break;
    }
    c[sz++] = i;
  }
  c[sz]='\0';
  return sz;
}
inline void wt_L(char a){
  putchar_unlocked(a);
}
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
int X;
int Y;
char A[100][102];
int r[100];
int c[100];
int main(){
  int i, j;
  rd(X);
  rd(Y);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<(X);Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  for(i=0;i<(X);i++){
    for(j=0;j<(Y);j++){
      if(A[i][j]=='#'){
        r[i] = c[j] = 1;
      }
    }
  }
  for(i=0;i<(X);i++){
    if(r[i]){
      for(j=0;j<(Y);j++){
        if(c[j]){
          wt_L(A[i][j]);
        }
      }
      wt_L('\n');
    }
  }
  return 0;
}
// cLay varsion 20190822-2

// --- original code ---
// int X, Y;
// char A[100][102];
// 
// int r[100], c[100];
// {
//   int i, j;
//   rd(X,Y,A(X));
//   rep(i,X) rep(j,Y) if(A[i][j]=='#') r[i] = c[j] = 1;
//   rep(i,X) if(r[i]){
//     rep(j,Y) if(c[j]) wtN(A[i][j]);
//     wtN('\n');
//   }
// }
