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
  ll n, k;
  string str;
  cin >> n >> str >> k;
  for(i = 0; i < n; i++){
    if(str[i] != str[k - 1])
      str[i] = '*';
  }
  cout << str << endl;

  return 0;
}