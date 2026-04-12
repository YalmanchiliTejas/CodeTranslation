#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <deque>
#include <tuple>
#include <unordered_set>
#include <array>
#include <string>

using namespace std;
#define ll long long
#define ar array

int main() {
	ll n, x, mod;
	cin >> n >> x >> mod;
	unordered_map<ll, ll> mp;
	ll c=1, curr=x, len=-1, total=0, magic=-1;
	while (1) {
		if (mp.find(curr)!=mp.end()) {
			len=c-mp[curr];
			magic=curr;
			break;
		}
		total+=curr;
		mp[curr]=c++;
		curr*=curr;
		curr%=mod;
	}
	curr=x;
	ll rest=0;
	c=0;
	while (1) {
		if (magic==curr) break;
		total-=curr;
		rest+=curr;
		curr*=curr;
		curr%=mod;
		c++;
	}
	ll times=(n-c)/len;
	ll ans=times*total+rest;
	c=n-times*len-c;
	while (c-->0) {
		ans+=magic;
		magic*=magic;
		magic%=mod;
	}
	cout << ans;
	
	return 0;
}