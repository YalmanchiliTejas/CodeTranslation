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
  int i;
  int sz = 0;
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
template<class T> int arrCountVal(int N, T A[], T val){
  int i;
  int res = 0;
  for(i=(0);i<(N);i++){
    if(A[i]==val){
      res++;
    }
  }
  return res;
}
int H;
int W;
char A[10];
int main(){
  int i;
  int cnt = 0;
  rd(H);
  rd(W);
  for(i=(0);i<(H);i++){
    rd(A);
    cnt += arrCountVal(W, A, '#');
  }
  if(cnt==H+W-1){
    wt_L("Possible");
    wt_L('\n');
  }
  else{
    wt_L("Impossible");
    wt_L('\n');
  }
  return 0;
}
// cLay varsion 20191125-1

// --- original code ---
// int H, W;
// char A[10];
// {
//   int cnt = 0;
//   rd(H,W);
//   rep(i,H) rd(A), cnt += arrCountVal(W, A, '#');
//   wt(if[cnt==H+W-1, "Possible", "Impossible"]);
// }
