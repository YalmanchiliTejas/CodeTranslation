#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1000000007;
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  int n;
  cin >> n;
  ll arr[n];
  for(int i = 0;i < n;i++)
    cin >> arr[i];
  sort(arr, arr + n);
  if(arr[n - 1] <= n - 1){
    cout << 0;
    return 0;
  }
  ll k = 0;
  ll res = 0;
  for(int i = n - 1;i >= 1;i--){
    ll op = (arr[i] - arr[i - 1]) / (n + 1);
    res += op * (n - i);
    for(int j = i;j < n;j++)
      arr[j] -= op * (i + 1);
    for(int j = 0;j < i;j++)
      arr[j] += op * (n - i);

  }
  if(arr[0] >= n){
    ll op = (arr[0] - (n - 1));
    res += n * op;
    for(int i = 0;i < n;i++)
      arr[i] -= op;
  }

  while(arr[n - 1] >= n){
    arr[n - 1] -= n;
    for(int j = 0;j < n - 1;j++)
      arr[j]++;
    for(int j = n - 1;j >= 1 && arr[j] < arr[j - 1];j--)
      swap(arr[j], arr[j - 1]);
    res++;
  }
  cout << res;
}

