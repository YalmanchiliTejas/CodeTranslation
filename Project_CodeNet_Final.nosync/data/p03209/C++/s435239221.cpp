#include <bits/stdc++.h>
using namespace std;

long long n, x;

vector<long long> brg;
vector<long long> pa;

long long solve(long long n, long long x){
  if(x <= 0) return 0;
  if(n == 0) return 1;
  if(x == 1) return 0;
   
  if(x <= brg.at(n-1) + 1) return solve(n-1, x-1);
  return solve(n-1, x-brg.at(n-1)-2) + pa.at(n-1) + 1;
}

int main(){
  cin >> n >> x;
  
  brg.resize(n+1);
  pa.resize(n+1);
  brg.at(0) = 1;
  pa.at(0) = 1;
  for(int i = 1; i < n+1; ++i){
    brg.at(i) = brg.at(i-1) * 2 + 3;
    pa.at(i) = pa.at(i-1) * 2 + 1;
  }
  
  cout << solve(n, x) << endl;
}