#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define INF (1LL<<60)


int main(){
	vector<pair<ll,ll> > v;
	int n;
	cin >> n;
	ll amx = 0;
	ll ami = INF;
	ll bmx = 0;
	ll bmi = INF;
	rep(i,n){
		ll x,y;
		cin >> x >> y;
		if(y>x){
			swap(x,y);
		}
		v.push_back(MP(x,y));
		amx = max(amx,x);
		ami = min(ami,x);
		bmx = max(bmx,y);
		bmi = min(bmi,y);
	}
	ll ans = (amx-ami)*(bmx-bmi);
	ll mx = amx;
	ll mi = bmi;
	sort(v.begin(),v.end(),greater<pair<ll,ll> >());
	vector<bool> flag(n);
	multiset<ll> st;
	rep(i,n){
		if(v[i].first==mx){
			flag[i] = true;
			st.insert(v[i].second);
		}else if(v[i].second==mi){
			flag[i] = true;
			st.insert(v[i].first);
		}else{
			st.insert(v[i].first);
		}
	}
	auto x = st.begin();
	auto y = st.end();
	y--;
	ans = min(ans,(mx-mi)*((*y)-(*x)));
	rep(i,n){
		if(!flag[i]){
			auto p = st.find(v[i].first);
			st.erase(p);
			st.insert(v[i].second);
			x = st.begin();
			y = st.end();
			y--;
			ans = min(ans,(mx-mi)*((*y)-(*x)));
		}
	}
	cout << ans << endl;
	return 0;
}