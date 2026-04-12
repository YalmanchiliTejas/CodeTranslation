//Har Har Mahadev
using namespace std;
#include <bits/stdc++.h>
#define booga cout << "booga" << endl
#define ll long long int
#define pb push_back
#define mp make_pair
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " -> " << a << endl;
	err(++it, args...);
}

void testcase(){
	ll n,x,m;
	cin >> n >> x >> m;
	vector<ll> a(m);
	a[0] = x;
	for(ll i{1};i < m;i++){
		if(a[i-1] == 0){
			a[i] = 0;continue;
		}
		a[i] = (a[i-1]*a[i-1]) % m;
		a[i] %= m;
	}
	map<ll,int> ind;
	int start = 0,end = 0;
	for(int i{0};i < n;i++){
		if(ind.find(a[i]) != ind.end()){
			start = ind[a[i]];end = i;break;
		}
		ind[a[i]] = i;
	}
	if(n <= m){
		ll sum = 0;
		for(int i{0};i < n;i++)sum += a[i];
		cout << sum;return;
	}
	//debug(start,end);
	ll sum = 0,inter = 0;
	for(int i{0};i < start;i++){
		sum += a[i];
	}
	for(int i{start};i < end;i++){
		inter += a[i];
	}
	n -= start;
	sum += inter * (n/(end - start));
	n %= (end - start);
	for(int i{0};i < n;i++){
		sum += a[i + start];
	}
	cout << sum;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	while(t--){
		testcase();
	}
	return 0;
}
