#include<bits/stdc++.h>
using namespace std;
void *wmem;
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
template<class T> int weaklyLIS_length(int n, T a[], void *mem = wmem){
  T *arr=(T*)mem;
  int i, k, res;
  if(n==0){
    return 0;
  }
  arr[0] = a[0];
  res = 1;
  for(i=1;i<n;i++){
    k = upper_bound(arr, arr+res, a[i]) - arr;
    arr[k] = a[i];
    if(res==k){
      res++;
    }
  }
  return res;
}
char memarr[96000000];
int N;
int A[100000];
int main(){
  int res;
  wmem = memarr;
  rd(N);
  {
    int Lj4PdHRW;
    for(Lj4PdHRW=0;Lj4PdHRW<N;Lj4PdHRW++){
      rd(A[Lj4PdHRW]);
    }
  }
  reverse(A,A+N);
  res = weaklyLIS_length(N, A);
  wt_L(res);
  wt_L('\n');
  return 0;
}
// cLay varsion 20190715-1

// --- original code ---
// int N, A[1d5];
// {
//   int res;
//   rd(N,A(N));
//   reverse(A,A+N);
//   res = weaklyLIS_length(N, A);
//   wt(res);
// }
