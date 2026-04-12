#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main() {
	ll N;
	cin >> N;
	map<char, ll>mp;
	map<char, ll>min_v;
	for (char c = 'a'; c <= 'z'; c++) {
		min_v[c] = 100000000;
	}

	for (ll i = 0; i < N; i++) {
      	string S;
		cin >> S;
		for (ll i = 0; i < S.size(); i++) {
			mp[S[i]]++;
		}
		for (char c = 'a'; c <= 'z'; c++) {
			min_v[c] = min(mp[c], min_v[c]);
          	mp[c]=0;
		}
	}
	string s = "";
	for (auto p : min_v) {
		ll x = p.first;
		ll y = p.second;
		for (ll i = 0; i < p.second; i++) {
			s += x;
		}
	}
	cout << s << endl;
}
	








