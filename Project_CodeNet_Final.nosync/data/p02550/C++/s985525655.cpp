#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define FOR(i, n) for(int i = 1; i<=n; i++)
#define F0R(i, n) for(int i = 0; i<n; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
LL n, MOD, x, ans = 0, sq, nosq;
vector<LL> seq, pf, oseq, bef;
map<LL, LL> prv;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n >> x >> MOD;
	LL tmp = x; prv[tmp] = 1;
	oseq.pb(tmp);
	tmp *= tmp; tmp %= MOD; int cur = 1;
	while(1){
		if(prv[tmp]) {
			for(int i = prv[tmp]-1; i<oseq.size(); i++)
				seq.pb(oseq[i]);
			for(int i = 0; i<prv[tmp]-1; i++)
				bef.pb(oseq[i]);
			break;
		}
		oseq.pb(tmp); cur++; prv[tmp] = cur; 
		tmp *= tmp;
		tmp %= MOD;
	}

	for(auto u : seq)
		pf.pb(u);

	for(int i = 1; i<seq.size(); i++)
		pf[i] += pf[i-1];

	sq = seq.size(); nosq = bef.size();
	if(n < nosq){
		for(int i = 0; i<n; i++)
			ans += bef[i];
		cout << ans << endl;
		return 0;
	}

	for(int i = 0; i<nosq; i++)
		ans += bef[i];
	n -= nosq;

	ans += (n/sq) * pf[sq-1];
	n %= sq;
	if(n != 0)ans += pf[n-1];
	cout << ans << endl;


	cout.flush();
	return 0;
}