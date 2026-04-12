#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, x;
ll all[51] ={}, pat[51] = {};
void init(){
  all[0] = 1;
  pat[0] = 1;
  for(int i=1;i<=50;i++){
    all[i] = all[i-1] * 2 + 3;
    pat[i] = pat[i-1] * 2 + 1;
  }
}

ll solve(ll n, ll x){
  if (x <= 1) return (n == 0?1:0);
  else if (x <= all[n-1] + 1) return solve(n-1, x-1);
  else if (x == all[n-1] + 2) return pat[n-1] + 1;
  else if (x <= 2 * all[n-1] + 2) return pat[n-1] + 1 + solve(n - 1, x - all[n-1] - 2);
  else return pat[n];
}

int main(){
  cin >> n >> x;
  init();
  cout << solve(n, x) << endl;
}
