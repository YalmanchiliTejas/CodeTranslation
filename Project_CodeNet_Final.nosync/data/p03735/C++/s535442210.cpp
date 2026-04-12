#include <cstdio>
#include <cstring>
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
#define INF 1100000000000000000LL
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;

int main()
{
	int n;
	scanf("%d", &n);
	vector<P> v;
	for(int i=0; i<n; i++){
		ll x, y;
		scanf("%lld %lld", &x, &y);
		if(x>y) swap(x, y);
		v.push_back(P(x, y));
	}
	sort(v.begin(), v.end());
	ll min=v[0].first;
	ll max=0;
	multiset<ll> st, st1, st2;
	for(int i=0; i<n; i++){
		st.insert(v[i].second);
		st2.insert(v[i].second);
		st1.insert(v[i].first);
		if(max<v[i].second) max=v[i].second;
	}
	auto itr1=st.begin(), itr2=st.end(); itr2--;
	ll ans1=max-min, ans2=*itr2-*itr1, ans;
	for(int i=n-1; i>=0; i--){
		st.insert(v[i].first);
		auto itr=st.lower_bound(v[i].second);
		st.erase(itr);
		auto itr1=st.begin(), itr2=st.end(); itr2--;
		if(ans2>*itr2-*itr1) ans2=*itr2-*itr1;
	}
	ans=ans1*ans2;
	itr1=st1.end(), itr2=st2.begin(); itr1--;
	if(ans>(*itr1-min)*(max-*itr2)) ans=(*itr1-min)*(max-*itr2);
	for(int i=n-1; i>=0; i--){
		st1.insert(v[i].second);
		auto itr=st1.lower_bound(v[i].first);
		st1.erase(itr);
		st2.insert(v[i].first);
		itr=st2.lower_bound(v[i].second);
		st2.erase(itr);
		auto itr1=st1.end(), itr2=st2.begin(); itr1--;
		if(ans>(*itr1-min)*(max-*itr2)) ans=(*itr1-min)*(max-*itr2);
	}
	printf("%lld\n", ans);
	return 0;
}