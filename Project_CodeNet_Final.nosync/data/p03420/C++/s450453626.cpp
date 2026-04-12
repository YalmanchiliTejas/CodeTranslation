#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef unsigned long long ull;
ll solve(int n, int k){
  ll res = 0;
  for(int i = k + 1;i <= n;i++){
    int segs = n / i;
    res += segs * (i - k) + max(0, (n - segs * i - max(0, k - 1)));
  }
  return res;
}
int brute(int n, int k){
  int res = 0;
  for(int i = 1;i <= n;i++)
    for(int j = 1;j <= n;j++)
      if(i % j >= k)res++;
  return res;
}
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n, k;
  cin >> n >> k;
  cout << solve(n, k);
  return 0;
}
