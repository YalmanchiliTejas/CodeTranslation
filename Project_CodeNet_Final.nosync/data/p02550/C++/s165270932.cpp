// E - Sequence Sum
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)

int main(){
	ll N; int X, M; cin>>N>>X>>M;

	int mn = min(N, (ll)M);
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
		if(a == 0){ cout<< ans <<endl; return 0; }
	}

	if((int)A.size() >= mn){ cout<< ans <<endl; return 0; }

	int st_len = 0;
	while(st_len < (int)A.size() && a != A[st_len]) st_len += 1;
	int cyc_len = A.size() - st_len;
	int ed_len = (N - st_len) % cyc_len;

	ll st = 0; rp(i, 0, st_len) st += A[i];
	ll cyc_sum = 0; rp(i, st_len, A.size()) cyc_sum += A[i];
	ll cyc_num = (N - st_len) / cyc_len;
	ll ed = 0; rp(i, st_len, st_len + ed_len) ed += A[i];

	cout<< st + cyc_sum * cyc_num + ed <<endl;
}
