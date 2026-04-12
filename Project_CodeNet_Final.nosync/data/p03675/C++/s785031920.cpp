#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pint = pair<int,  int>;
using pll = pair<ll, ll>;
using edge = pair<int, ll>;
using graph = vector<vector<int>>; 
using WeightedGraph = vector<vector<edge>>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main() {
  ll n;cin >> n;
  vector<ll> a(n), b(n);
  for(int i = 0; i < n; ++i)cin >> a[i];
  int num = 0;
  for(int i = n-1; i >= 0; --i){
    if(num%2==0){
      b[num/2]=a[i];
    }
    else{
      b[n-1-num/2]= a[i];
    }
    ++num;
  }
  for(int i = 0; i < n; ++i){
    cout << b[i];
    if(i==n-1){
      cout << endl; 
    }
    else{
      cout << ' ';
    }
  }
}
