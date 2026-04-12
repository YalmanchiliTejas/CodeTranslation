#include <bits/stdc++.h>
using namespace std;


vector<long long> sou(51), patty(51);

long long solve(long long n, long long x){
  if (n==0) return 1;
  else if (x==1) return 0;
  else if (x<=sou[n-1]+1) return solve(n-1, x-1);
  else if (x==sou[n-1]+2) return patty[n-1]+1;
  else if (x==sou[n]) return patty[n];
  else return patty[n-1] + 1 + solve(n-1, x-(sou[n-1]+2));
}

int main(){
  long long N, X;
  cin >> N >> X;
  sou[0] = 1; patty[0] = 1;
  for (int i=1; i<=N; i++){
    sou[i] = 2*sou[i-1]+3;
    patty[i] = 2*patty[i-1]+1;
  }
  cout << solve(N,X) << endl;
}
