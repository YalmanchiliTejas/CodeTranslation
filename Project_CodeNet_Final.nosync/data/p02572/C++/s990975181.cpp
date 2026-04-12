#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  
  int n;
  cin >> n;
  vector<ll> vec(n);
  vector<ll> mo(n-1);
  
  for (int i =0;i<n;i++) cin >> vec.at(i);
  mo.at(n-2) = vec.at(n-1);
  for (int i=3;i<n+1;i++){
    mo.at(n-i) = (mo.at(n-i+1)+vec.at(n-i+1))%1000000007;
  }
  ll sum=0;
  for (int i=0;i<n-1;i++){
    sum += (vec.at(i)*mo.at(i))%1000000007;
    ;
    sum %= 1000000007;
  }
  cout << sum <<endl;
 
}
