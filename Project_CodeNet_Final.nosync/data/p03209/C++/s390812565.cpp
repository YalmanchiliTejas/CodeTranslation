#include <math.h>
#include <bits/stdc++.h>
using namespace std;

long long p[51];
long long l[51];


long long solve(int n, long long x){

  if(x ==0) return 0LL;
  else if(x >= l[n]) return p[n];
  else if(x >= l[n-1]+2) return solve(n-1, x-l[n-1]-2) + p[n-1]+1; 
  else if(x < l[n-1]+2) return solve(n-1, x-1);
}


int main(void){
  int N;
  long long X;
  cin >> N >> X;
  p[0]=1LL; l[0]=1LL;
  for(int i=0; i<N; i++){
    l[i+1] = 2*l[i]+3; p[i+1] = 2*p[i]+1;
  }
  long long ans;
  ans = solve(N, X);
  printf("%lld\n", ans);
  return 0;
}
