#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
ll MOD = 1e9+7;
void chmin(ll &a, ll b) { if (a > b) a = b; }
void chmax(ll &a, ll b) { if (a < b) a = b; }

int main(){
  ll i, j;
  ll n;
  cin >> n;
  vector<ll> h(n);
  for(i = 0; i < n; i++)
    cin >> h[i];
  ll result = 0;
  ll max = 0;
  for(i = 0; i < n; i++)
    if(max <= h[i]){
      result++;
      max = h[i];
    }
  
  cout << result << endl;

  return 0;
}