#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long  ll; typedef vector<int> VI; typedef pair<int,int> pii; typedef vector<ll> VL; const int MD = 1e9 + 7;
void dbg(){cerr<<"\n";} template <class F,class ...S> void dbg(const F& f, const S&...s){cerr <<f <<": "; dbg(s...);}


int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >>n;
	VL a(n), sm(n+1);
	rep(i, n) cin >>a[i];
	ll bans = 0, ans =0;
	//rep(i, n) rep2(j, i+1, n) (bans += a[i]*a[j])%=MD;
	//dbg(bans);
	rep(i,n) sm[i+1] = (sm[i] + a[i])%MD;
	rep(i, n-1){
		(ans += a[i] * (sm[n] + MD - sm[i+1])) %=MD;
	}
	
	cout <<ans <<"\n";
	return 0;
}

