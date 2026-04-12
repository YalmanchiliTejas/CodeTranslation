#include <bits/stdc++.h>
using namespace std;

int N;
long long l[51];
long long p[51];

long long solve(int n, long long x){
  if(x == 0){
    return 0LL;
  }else if(x >= l[n]){
    return p[n];
  }else if(l[n-1] + 2 <= x){
    return solve(n-1, x-l[n-1]-2) + p[n-1] + 1;
  }else if(x < l[n-1]+2){
    return solve(n-1, x-1);
  }
}

int main(int arvc, char** argv){
  long long X;
  cin >> N >> X;

  l[0]=1LL;
  p[0]=1LL;
//  cout << "malloc ok" << endl;
  
  for(int cnt0=1; cnt0<N+1; cnt0++){
    l[cnt0] = 2*l[cnt0-1] + 3;
    p[cnt0] = 2*p[cnt0-1] + 1;    
  }

//  cout << "sequence ok" << endl;
  
  long long ans = solve(N, X);
  
  printf("%lld", ans);
}