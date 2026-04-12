#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define eb emplace_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define ub(v,k) (upper_bound(all(v),k)-v.begin())
#define fi first
#define se second
#define pi M_PI
#define PQ(T) priority_queue<T>
#define SPQ(T) priority_queue<T,vector<T>,greater<T>>
#define dame(a) {out(a);return 0;}
#define decimal cout<<fixed<<setprecision(15);
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef tuple<ll,ll,ll,ll> PPP;
typedef multiset<ll> S;
using vi=vector<ll>;
using vvi=vector<vi>;
using vvvi=vector<vvi>;
using vp=vector<P>;
using vvp=vector<vp>;
using vb=vector<bool>;
using vvb=vector<vb>;
const ll inf=1001001001001001001;
const int INF=1001001001;
const int mod=1000000007;
const double eps=1e-10;
template<class T> bool chmin(T&a,T b){if(a>b){a=b;return true;}return false;}
template<class T> bool chmax(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T> void out(T a){cout<<a<<'\n';}
template<class T> void outp(T a){cout<<'('<<a.fi<<','<<a.se<<')'<<'\n';}
template<class T> void outvp(T v){rep(i,v.size())cout<<'('<<v[i].fi<<','<<v[i].se<<')';cout<<'\n';}
template<class T> void outvvp(T v){rep(i,v.size())outvp(v[i]);}
template<class T> void outv(T v){rep(i,v.size()){if(i)cout<<' ';cout<<v[i];}cout<<'\n';}
template<class T> void outvv(T v){rep(i,v.size())outv(v[i]);}
template<class T> bool isin(T x,T l,T r){return (l)<=(x)&&(x)<=(r);}
template<class T> void yesno(T b){if(b)out("yes");else out("no");}
template<class T> void YesNo(T b){if(b)out("Yes");else out("No");}
template<class T> void YESNO(T b){if(b)out("YES");else out("NO");}
template<class T> void noyes(T b){if(b)out("no");else out("yes");}
template<class T> void NoYes(T b){if(b)out("No");else out("Yes");}
template<class T> void NOYES(T b){if(b)out("NO");else out("YES");}
void outs(ll a,ll b){if(a>=inf-100)out(b);else out(a);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll modpow(ll a,ll b){a%=mod;if(b==0)return 1;if(b&1)return a*modpow(a,b-1)%mod;ll k=modpow(a,b/2);return k*k%mod;}

struct segment {
	int l, r; long long score;
	segment(int l_, int r_, long long score_) : l(l_), r(r_), score(score_) {};
};
bool operator<(const segment& s1, const segment& s2) {
	return s1.score != s2.score ? s1.score < s2.score : (s1.l != s2.l ? s1.l < s2.l : s1.r < s2.r);
}
vector<long long> solve(int N, vector<long long> A) {
	vector<long long> sa(N + 2);
	for (int i = 0; i < N; ++i) {
		sa[i + 2] = sa[i] + A[i];
	}
	function<long long(int, int)> getsum = [&](int l, int r) {
		return sa[r + 1] - sa[l];
	};
	priority_queue<segment> que;
	set<segment> s, cand;
	for (int i = 0; i < N; ++i) {
		que.push(segment(i, i + 1, A[i]));
		cand.insert(segment(i, i + 1, 0));
	}
	vector<long long> ans((N + 1) / 2);
	long long cur = 0;
	for (int i = 0; i < (N + 1) / 2; ++i) {
		while (true) {
			segment x = que.top(); que.pop();
			if (cand.find(segment(x.l, x.r, 0)) == cand.end()) continue;
			cand.erase(segment(x.l, x.r, 0));
			cur += x.score;
			int sl = x.l, sr = x.r;
			s.erase(segment(sl + 1, sr - 1, 0));
			set<segment>::iterator it = s.lower_bound(segment(sl, sr, 0)), rit = it;
			if (it != s.begin() && (--it)->r == sl - 1) {
				segment sel = *it;
				s.erase(it);
				cand.erase(segment(sel.l - 1, sel.r + 1, 0));
				sl = sel.l;
			}
			it = rit;
			if (it != s.end() && it->l == sr + 1) {
				segment sel = *it;
				s.erase(it);
				cand.erase(segment(sel.l - 1, sel.r + 1, 0));
				sr = sel.r;
			}
			cand.erase(segment(sl - 1, sl, 0));
			cand.erase(segment(sr, sr + 1, 0));
			s.insert(segment(sl, sr, 0));
			if (sl != 0 && sr != N) {
				cand.insert(segment(sl - 1, sr + 1, 0));
				que.push(segment(sl - 1, sr + 1, getsum(sl - 1, sr + 1) - getsum(sl, sr)));
			}
			ans[i] = cur;
			break;
		}
	}
	return ans;
}
int main() {
	int N;
	cin >> N;
	vector<long long> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	vector<long long> ans = solve(N, A);
	out(ans[N/2-1]);
	return 0;
}
