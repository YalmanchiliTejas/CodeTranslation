#include<bits/stdc++.h>
#include<vector>

#define pb push_back
#define rep(i, a, n) for(int (i)=a; (i)<(n); (i)++)
#define FOR(i, n) rep(i, 0, n)
#define F(n) FOR(i, n)
#define FF(n) FOR(j, n)
#define repi(i, a, n) for(int (i)=a; (i)<=(n); (i)++)
#define FORI(i, n) repi(i, 1, n)
#define FI(n) FORI(i, n)
#define FFI(n) FORI(j, n)
#define IN(x) int x; cin>>(x);
#define SIN(x) string x; cin>>x;
#define INN(x, y) int x, y; cin>>(x)>>(y);
#define INFO(a) cout<<"info "<<a<<endl
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define vpii vector<pair<int, int> >
#define sortv(x) sort((x).begin(), (x).end())
#define sortvd(x) sort((x).begin(), (x).end(), greater<int>())
#define lboundv(x,v) lower_bound((x).begin(),(x).end(),(v))-(x).begin();
#define uboundv(x,v) upper_bound((x).begin(),(x).end(),(v))-(x).begin();
#define ite iterator
#define fi first
#define se second
#define mems(a, v) memset((a), (v), sizeof((a)))
#define lmid(l, r) ((l)+(r)-1)/2
#define rmid(l, r) ((l)+(r))/2+1
#define mp make_pair

typedef long long ll;
typedef long double LD;

using namespace std;

#define N 500005
int main() {
	ios::sync_with_stdio(0);
	SIN(s);
	F(s.size()-1) {
		if(s[i]=='A' && s[i+1]=='C') {cout<<"Yes"<<endl; return 0;}
	}
	cout<<"No"<<endl;
	return 0;
}