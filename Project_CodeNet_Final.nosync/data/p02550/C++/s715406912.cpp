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
	ll sum_9 = 0; // sum of pre + cycle

	rp(_i, 0, mn){
		if(S.find(a) != S.end()) break;
		S.insert(a);
		A.push_back(a);
		sum_9 += a;
		a = a*a % M;
		if(a == 0){ cout<< sum_9 <<endl; return 0; }
	}

	if((int)A.size() >= mn){ cout<< sum_9 <<endl; return 0; }

	int pre_len = find(A.begin(), A.end(), a) - A.begin();
	int cyc_len = A.size() - pre_len;
	int btm_len = (N - pre_len) % cyc_len;

	ll cyc_num = (N - pre_len) / cyc_len;

	ll pre = 0; rp(i, 0, pre_len) pre += A[i];
	ll cyc = sum_9 - pre;
	ll btm = 0; rp(i, pre_len, pre_len + btm_len) btm += A[i];

	cout<< pre + cyc * cyc_num + btm <<endl;
}
