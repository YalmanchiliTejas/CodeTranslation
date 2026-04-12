// E - Sequence Sum
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rp(i,s,e) for(ll i=(ll)(s);i<(ll)(e);++i)

int main(){
	ll N, X, M; cin>>N>>X>>M;

	ll mn = min(N, M);
	set<ll> S;
	vector<ll> A;
	ll a = X;
	ll ans = 0;

	rp(_i, 0, mn){
		if(S.find(a) != S.end()) break;
		S.insert(a);
		A.push_back(a);
		ans += a;
		a = a*a % M;
		a = (a + M) % M;
		if(a == 0){
			cout<< ans <<endl;
			return 0;
		}
	}

	if((ll)A.size() >= mn){
		cout<< ans <<endl;
		return 0;
	}

	ll st_len = 0;
	while(st_len < (ll)A.size() && a != A[st_len]) st_len += 1;
	ll st = 0; rp(i, 0, st_len) st += A[i];
	ll cyc_sum = 0; rp(i, st_len, A.size()) cyc_sum += A[i];
	ll cyc_len = A.size() - st_len;
	ll cyc_num = (N - st_len) / cyc_len;
	ll ed_len = (N - st_len) % cyc_len;
	ll ed = 0; rp(i, st_len, st_len + ed_len) ed += A[i];
	cout<< st + cyc_sum * cyc_num + ed <<endl;
}
