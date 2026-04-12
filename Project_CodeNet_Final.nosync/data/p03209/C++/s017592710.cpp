#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

map<int,ll> m,f;
// m: num of (p and b)
// f: num of p
int N;
ll X;

ll solve(int n, ll x){
  if(x == 1){
    if(n == 0){
      return 1;
    } else {
      return 0;
    }
  }
  if(x <= 1 + m[n-1]){
    return solve(n-1, x-1);
  }
  if(x == 2 + m[n-1]){
    return f[n-1] + 1;
  }

  if(x <= 2 + m[n-1] + m[n-1]){
    return f[n-1] + 1 + solve(n-1, x-2-m[n-1]);
  }

  if(x == 2 * m[n-1] + 3){
    return f[n-1]*2 + 1;
  }
}

int main(){
  cout << setprecision(10);
  cin >> N >> X;

  for(int i = 0; i <= N; i++){
    if(i == 0){
      m[i] = 1;
      f[i] = 1;
    } else { 
      m[i] = m[i-1] * 2 + 3;
      f[i] = f[i-1] * 2 + 1;
    }
  }
  cerr << solve(N,X) << endl;
  cout << solve(N,X) << endl;
}
