#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, X, M;

void solve()
{
	set<ll> seen;
	ll cur = X;
	vector<ll> v;
	while((int)v.size()<N){
		if(seen.count(cur)) break;
		seen.insert(cur);
		v.push_back(cur);
		(cur *= cur)%=M;
	}
	ll res = 0;
	if((int)v.size()>=N) res=accumulate(v.begin(),v.end(),0LL);
	else{
		const int n = v.size();
		int idx=0;
		while(v[idx]!=cur) idx++;
		const int L = n-idx;
		for(int i=0;i<idx;++i) res+=v[i];
		N-=idx;
		res += (N/L)*accumulate(v.begin()+idx,v.end(),0LL);
		N%=L;
		int i=idx;
	    while(N>0) res+=v[i++], N--;
	}
	cout<<res<<'\n';
}

int main()
{
	cin >> N >> X >> M;
	solve();
	return 0;
}