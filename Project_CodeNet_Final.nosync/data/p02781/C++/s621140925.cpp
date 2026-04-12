#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

string N;
int n,K;

long long comb(long long n,long long k) {
  if(n < 0 || k > n) return 0;
  if(k == 1) return n;
  else if(k == 2) return n*(n-1)/2;
  else return n*(n-1)*(n-2)/6;
}

long long pow(long long l) {
  long long res = 1;
  for(int i = 0;i < l;i++) res *= 9;
  return res;
}

long long solve(int i,bool smaller,int k) {
  if(i == n) {
    if(k == 0) return 1;
    else return 0;
  }
  if(k == 0) return 1;

  if(smaller) return comb(n-i,k)*pow(k);
  else {
    if(N.at(i) == '0') return solve(i+1,false,k);
    else {
      long long z = solve(i+1,true,k);
      long long m = solve(i+1,true,k-1)*(N.at(i)-'1');
      long long s = solve(i+1,false,k-1);
      return z+m+s;
    }
  }
  
}

int main() {
  
  cin >> N >> K;
  n = N.size();
  cout << solve(0,false,K) << endl;

  
}
