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
int N;
int M;
int A;
int B;
int mat[8][8];
int main(){
  int Lj4PdHRW, i, ind[8], res=0;
  rd(N);
  rd(M);
  for(Lj4PdHRW=0;Lj4PdHRW<(M);Lj4PdHRW++){
    rd(A);A += (-1);
    rd(B);B += (-1);
    mat[A][B] = mat[B][A] = 1;
  }
  for(i=0;i<(N);i++){
    ind[i] = i;
  }
  do{
    for(i=(1);i<(N);i++){
      if(!mat[ind[i-1]][ind[i]]){
        break;
      }
    }
    if(i==N){
      res++;
    }
  }
  while(next_permutation(ind+1, ind+N));
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190829-1

// --- original code ---
// int N, M, A, B;
// int mat[8][8];
// {
//   int i, res = 0;
//   int ind[8];
//   
//   rd(N,M);
//   rep(M){
//     rd(A--,B--);
//     mat[A][B] = mat[B][A] = 1;
//   }
// 
//   rep(i,N) ind[i] = i;
//   do{
//     rep(i,1,N) if(!mat[ind[i-1]][ind[i]]) break;
//     if(i==N) res++;
//   }while(next_permutation(ind+1, ind+N));
// 
//   wt(res);
// }
