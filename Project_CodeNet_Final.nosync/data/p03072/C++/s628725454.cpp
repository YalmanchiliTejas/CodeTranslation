#include <bits/stdc++.h>
#define FOR(i, begin, end) for(ll i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(ll i=(begin);i>(end);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define ISORT(a) sort(a.begin(), a.end(),greater<ll>())
#define REVERSE(a) reverse(a.begin(), a.end())
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;}

#define ll long long
#define f first
#define s second
using namespace std;

using vec = vector<ll>;
using mat = vector<vec>;
using Pii = pair<ll, ll>;
using PiP = pair<ll, Pii>;
using PPi = pair<Pii, ll>;

int main()
{
	// 入力
	ll N;
	cin >> N;

	vec H(N);
	vec maxH(N);
	maxH[0]=0;
	REP(i, N) {
		cin>>H[i];
		if(i==0) maxH[i]=H[i];
		else maxH[i]=max(H[i],maxH[i-1]);
	}

	ll ans=1;

	FOR(i,1,N){
		if(maxH[i-1]<=H[i]) ans++;
	}

	cout<<ans<<endl;

	return 0;
}