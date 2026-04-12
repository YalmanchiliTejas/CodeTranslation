// E - Sequence Sum
#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)

int main(){
	ll N; int X, M; cin>>N>>X>>M;

	int mn = min(N, (ll)M);
	set<int> S;
	vector<int> A;
	ll sum_9 = 0; // sum of pre + cycle

	rp(_i, 0, mn){
		if(S.find(X) != S.end()) break;
		S.insert(X);
		A.push_back(X);
		sum_9 += X;
		X = (ll)X*X % M;
	}

	if((int)A.size() >= mn){ cout<< sum_9 <<endl; return 0; }

	int pre_len = find(A.begin(), A.end(), X) - A.begin();
	int cyc_len = A.size() - pre_len;
	int nxt_len = (N - pre_len) % cyc_len;

	ll cyc_num = (N - pre_len) / cyc_len;

	ll pre = 0; rp(i, 0, pre_len) pre += A[i];
	ll cyc = sum_9 - pre;
	ll nxt = 0; rp(i, pre_len, pre_len + nxt_len) nxt += A[i];

	cout<< pre + cyc * cyc_num + nxt <<endl;
}
