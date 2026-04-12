#include <bits/stdc++.h>
#define ll long long int
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define pb(v, a) v.push_back(a)
#define Sort(v) sort(v.begin(), v.end())
#define For(m) for (auto it = m.begin(); it != m.end(); it++)
#define mod 1000000007
#define PI 3.14159265358979323846
#define fast                                                                   \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
using namespace std;

  
int main() {
  fast 
  ll n;
  cin >> n;
  ll arr[n];
  ll m1 =0;
  fr(i,0,n)
  {
      cin >> arr[i];
  }
  ll cnt=0;
  fr(i,0,n)
  {
      if(m1<=arr[i])
      {
          cnt++;
      }
      m1=max(m1,arr[i]);
  }
  cout << cnt;
  return 0;
}
