#include<bits/stdc++.h>
#include<bitset>
using namespace std;
using ll =long long;
const ll  p = 1e9 + 7;
ll mod_inv(ll x, ll prime = p){
    ll y = p-2;
    bitset<64> y_(y);
  ll ans = 1L;
  while(y){
      
    if(y&1){
      ans = (ans * x)%prime;
    }
    x = (x*x)%prime;
    y >>= 1;
    y_>>=1;
  }
  
  return ans;
}

int main(){
  int N;
  cin>>N;
  vector<ll> a(N);
  int i = 0;
  while(cin>>a[i++]);
  ll sum_of_squares = accumulate(a.begin(), a.end(), 0, [](ll prev, ll cur){return(prev  + cur*cur%p)%p;});
  ll sum = accumulate(a.begin(), a.end(), 0, [](ll prev, ll cur){return (prev  + cur)%p;});
  ll square_of_sum = sum* sum %p;
//   cout<<"mod_inv(2) = "<<mod_inv(2)<<endl;
  cout<<(square_of_sum - sum_of_squares + p)*mod_inv(2)%p;
}