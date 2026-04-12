#include <bits/stdc++.h>

using namespace std;

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const ll mod = 1e9+7;



int main()
{
	
	int n;
	cin >>n;
	vector<ll> a(n), b;
	rep(i,n) cin >>a[i];
	b=a;
	ll sm=0;
	repr(i,56,0){
		ll p = (1LL<<i);
		for(;;){
			auto mi = max_element(all(b));
			if(*mi < p * n) break;
			sm += p;
			*mi -= p * n + p;
			rep(j,n) b[j] += p;
		}
		
	}
	//for(auto x :b) printf("%lld, ",x); puts("");
	cout << sm << endl;
	return 0;
}
