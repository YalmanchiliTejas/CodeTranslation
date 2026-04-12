#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
int N; cin >> N;
  
  multiset<ll> mp;
  
  for(int i = 0; i < N; i++){
    ll a; cin >> a;
    auto itr = mp.lower_bound(a);
    if( itr == mp.begin()){
      mp.insert(a);}
    else{ itr--;
      mp.erase(itr); mp.insert(a);}
  }
  
  cout << (ll) mp.size() << endl; return 0;}