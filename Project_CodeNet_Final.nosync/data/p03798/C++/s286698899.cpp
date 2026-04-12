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
inline void wt_L(const char c[]){
  int i=0;
  for(i=0;c[i]!='\0';i++){
    putchar_unlocked(c[i]);
  }
}
int N;
char S[100002];
char res[100002];
int main(){
  int a, b, i, j, k;
  rd(N);
  rd(S);
  for(i=0;i<(N);i++){
    if(S[i]=='o'){
      S[i] =0;
    }
    else{
      S[i] =1;
    }
  }
  for(a=0;a<(2);a++){
    for(b=0;b<(2);b++){
      res[0] = a;
      res[1] = b;
      for(i=(2);i<(N);i++){
        res[i] = (res[i-2] + res[i-1] + S[i-1]) % 2;
      }
      if( (res[N-2] + res[N-1] + S[N-1] + res[0]) % 2 ){
        continue;
      }
      if( (res[N-1] + res[0] + S[0] + res[1]) % 2 ){
        continue;
      }
      for(i=0;i<(N);i++){
        if(res[i]==0){
          res[i] ='S';
        }
        else{
          res[i] ='W';
        }
      }
      wt_L(res);
      wt_L('\n');
      return 0;
    }
  }
  wt_L(-1);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190902-1

// --- original code ---
// int N;
// char S[100002];
// char res[100002];
// {
//   int i, j, k, a, b;
//   rd(N,S);
//   rep(i,N) S[i] = if[S[i]=='o', 0, 1];
//   rep(a,2) rep(b,2){
//     res[0] = a;
//     res[1] = b;
//     rep(i,2,N) res[i] = (res[i-2] + res[i-1] + S[i-1]) % 2;
//     if( (res[N-2] + res[N-1] + S[N-1] + res[0]) % 2 ) continue;
//     if( (res[N-1] + res[0] + S[0] + res[1]) % 2 ) continue;
//     rep(i,N) res[i] = if[res[i]==0, 'S', 'W'];
//     wt(res);
//     return 0;
//   }
//   wt(-1);
// }
