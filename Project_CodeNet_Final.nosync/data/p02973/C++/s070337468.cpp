#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll n;
  	cin >> n;
  	vector<ll> a(n);
  	for(auto& i : a) cin >> i;
  	multiset<ll, greater<ll>> s;
  	for(auto& i : a){
      	auto p = s.upper_bound(i);
     	if(p != s.end()) s.erase(p);
      	s.insert(i);
    }
  	cout << s.size() << endl;
}
