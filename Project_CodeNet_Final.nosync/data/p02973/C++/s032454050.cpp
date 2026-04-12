#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;
const ll MAXN = 1e5 + 5;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, color = 1;
  cin >> n;
  vector < ll > a(n + 1), c(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  set < pair < ll, ll > > s;
  s.insert({a[1], 1});
  for(int i = 2; i<= n; i++){
    auto it = s.lower_bound({a[i], LLONG_MIN});
    if(it != s.begin()){
      --it;
      s.insert({a[i], it -> second});
      s.erase(it);
    }else{
      color++;
      s.insert({a[i], color});
    }
  }

  cout << color << endl;
}
