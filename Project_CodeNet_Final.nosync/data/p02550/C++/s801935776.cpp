#include<bits/stdc++.h>
using ll = int_fast64_t;
#define REP(i,b,e) for(ll i=b; i<e; i++)
#define PRINT(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");

int main(){
	ll n, x, m;
	scanf("%ld %ld %ld", &n, &x, &m);
	std::vector<ll> vec;
	vec.push_back(x);
	std::set<ll> st;
	st.insert(x);
	ll ans = x, pre = x, idx = 0;
	REP(I, 2, n+1){
		pre = pre * pre % m;
		if(st.count(pre)){
			idx = I-1;
			int pos;
			REP(i, 0, vec.size()) if(vec[i]==pre) pos = i;
			ll r = 0;
			REP(i, pos, vec.size()) r += vec[i];
			ans += (n-idx)/(vec.size()-pos) * r;
			REP(i, pos, pos+((n-idx)%(vec.size()-pos))) ans += vec[i];
			printf("%ld\n", ans);
			return 0;
		}
		ans += pre;
		vec.push_back(pre);
		st.insert(pre);
	}
	printf("%ld\n", ans);
	return 0;
}

