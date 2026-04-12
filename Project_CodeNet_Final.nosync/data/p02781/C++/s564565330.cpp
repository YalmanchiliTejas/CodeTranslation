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
    putchar_unlocked('-');
  }
  while(s--){
    putchar_unlocked(f[s]+'0');
  }
}
int N;
int K;
char S[105];
int dp[2][5];
int nx[2][5];
int main(){
  int Q5VJL1cS;
  int i;
  int d;
  int a;
  int b;
  int na;
  int nb;
  int res = 0;
  N = rd(S);
  rd(K);
  dp[1][0] = 1;
  for(i=(0);i<(N);i++){
    S[i] -= '0';
  }
  for(Q5VJL1cS=(0);Q5VJL1cS<(N);Q5VJL1cS++){
    auto &k = S[Q5VJL1cS];
    for(a=(0);a<(2);a++){
      for(b=(0);b<(4);b++){
        nx[a][b] = 0;
      }
    }
    for(a=(0);a<(2);a++){
      for(b=(0);b<(4);b++){
        for(d=(0);d<(10);d++){
          na = a;
          nb = b;
          if(d){
            nb++;
          }
          if(a==1 && d > k){
            continue;
          }
          if(d < k){
            na = 0;
          }
          nx[na][nb] += dp[a][b];
        }
      }
    }
    for(a=(0);a<(2);a++){
      for(b=(0);b<(4);b++){
        dp[a][b] = nx[a][b];
      }
    }
  }
  for(a=(0);a<(2);a++){
    res += dp[a][K];
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20200214-1

// --- original code ---
// int N, K; char S[105];
// int dp[2][5], nx[2][5];
// 
// {
//   int i, d, a, b, na, nb, res = 0;
//   rd(S@N,K);
// 
//   dp[1][0] = 1;
//   rep(i,N) S[i] -= '0';
// 
//   rep[S](k,N){
//     rep(a,2) rep(b,4) nx[a][b] = 0;
//     rep(a,2) rep(b,4) rep(d,10){
//       na = a;
//       nb = b;
//       if(d) nb++;
//       if(a==1 && d > k) continue;
//       if(d < k) na = 0;
//       nx[na][nb] += dp[a][b];
//     }
//     rep(a,2) rep(b,4) dp[a][b] = nx[a][b];
//   }
// 
//   rep(a,2) res += dp[a][K];
//   wt(res);
// }
