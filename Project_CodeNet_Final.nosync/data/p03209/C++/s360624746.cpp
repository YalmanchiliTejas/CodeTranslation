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
inline void rd(long long &x){
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
inline void wt_L(long long x){
  char f[20];
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
long long X;
long long sz[51];
long long p[51];
int main(){
  int i, j, k;
  long long res=0;
  rd(N);
  rd(X);
  sz[0] = p[0] = 1;
  for(i=1;i<N+1;i++){
    sz[i] = 3 + 2*sz[i-1];
    p[i] = 1 + 2*p[i-1];
  }
  while(N){
    X--;
    if(X==0){
      break;
    }
    if(X < sz[N-1]){
      N--;
      continue;
    }
    X -= sz[N-1];
    res += p[N-1];
    if(X==0){
      break;
    }
    X--;
    res++;
    if(X==0){
      break;
    }
    if(X < sz[N-1]){
      N--;
      continue;
    }
    X -= sz[N-1];
    res += p[N-1];
    if(X==0){
      break;
    }
    X--;
    if(X==0){
      break;
    }
  }
  if(X==1){
    res++;
  }
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190715-1

// --- original code ---
// int N;
// ll X;
// 
// ll sz[51], p[51];
// 
// {
//   int i, j, k;
//   ll res = 0;
// 
//   rd(N,X);
// 
//   sz[0] = p[0] = 1;
//   rep(i,1,N+1){
//     sz[i] = 3 + 2sz[i-1];
//     p[i] = 1 + 2p[i-1];
//   }
// 
//   while(N){
//     X--;
//     if(X==0) break;
// 
//     if(X < sz[N-1]){ N--; continue; }
// 
//     X -= sz[N-1];
//     res += p[N-1];
//     if(X==0) break;
// 
//     X--;
//     res++;
//     if(X==0) break;
// 
//     if(X < sz[N-1]){ N--; continue; }
//     X -= sz[N-1];
//     res += p[N-1];
//     if(X==0) break;
// 
//     X--;
//     if(X==0) break;
//   }
//   if(X==1) res++;
// 
//   wt(res);
// }
