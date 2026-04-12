#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#include <list>
#define popcount __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
	ll n;
	ll x, m;
	cin>>n>>x>>m;
	vector<ll> v, v0{x};
	bool used[100010]={};
	used[x]=1;
	for(int i=1; i<=m; i++){
		x=x*x%m;
		if(used[x]){
			break;
		}
		used[x]=1;
		v0.push_back(x);
	}
	while(!v0.empty()){
		ll x1=v0.back(); v0.pop_back();
		v.push_back(x1);
		if(x1==x) break;
	}
	reverse(v.begin(), v.end());
	if(v0.size()>=n){
		ll ans=0;
		for(int i=0; i<n; i++){
			ans+=v0[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	ll ans=0;
	for(auto x:v0) ans+=x;
	n-=(ll)v0.size();
	ll s=0;
	for(auto x:v) s+=x;
	ll l=v.size();
	ans+=s*(n/l);
	for(int i=0; i<n%l; i++) ans+=v[i];
	cout<<ans<<endl;
	return 0;
}

