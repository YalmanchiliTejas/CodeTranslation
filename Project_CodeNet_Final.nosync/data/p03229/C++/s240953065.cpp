#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
ll MOD = 1e9+7;
void chmin(long long &a, long long b) { if (a > b) a = b; }

int main(){
  ll i, j;
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(i = 0; i < n; i++)
    cin >> a[i];
  sort(ALL(a));
  vector<ll> b(n - 1);
  for(i = 0; i < n - 1; i++)
    b[i] = a[i + 1] - a[i];
  
  //cout << n spa b[0] spa b[1] spa b[2] spa b[3] << endl;
  ll result = 0;
  if(n % 2 == 0){
    for(i = 0; i < n / 2 - 1; i++)
      result += 2 * (i + 1) * b[i];
    
    for(i = 0; i < n / 2 - 1; i++)
      result += 2 * (i + 1) * b[n - i - 2];
    result += b[n / 2 - 1] * (n - 1);
  }
  else{
    for(i = 0; i < n / 2 - 1; i++)
      result += 2 * (i + 1) * b[i];
    for(i = 0; i < n / 2 - 1; i++)
      result += 2 * (i + 1) * b[n - i - 2];
    result += (n - 1) * max(b[n / 2], b[n / 2 - 1]);
    result += (n - 2) * min(b[n / 2], b[n / 2 - 1]);
    
  }  
  cout << result << endl;

  return 0;
}