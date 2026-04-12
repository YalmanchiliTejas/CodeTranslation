#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1

ll n,m,k;
vector<ll> d;
vector<ll> id;
vector<vector<ll>> v;

ll solve(){
	ll res = 0;
	queue<P> que;
	vector<bool> used(1LL << m,false);
	que.push(P((1LL << m) - 1,0));
	while(que.size()){
		P p = que.front();
		que.pop();
		ll now = p.first;
		ll cnt = p.second;
		// cout << "!" << now << endl;
		if(used[now])continue;
		used[now] = true;
		if(now == 0){
			res = cnt;
			break;
		}
		rep(i,k){
			ll nxt = 0;
			rep(j,m){
				if(now & (1LL << j)){
					ll to = v[d[j]][i];
					if(id[to] == -1)continue;
					nxt |= (1LL << id[to]);
				}
			}
			que.push(P(nxt,cnt+1));
		}
	}
	return res;
}

int main(){
	cin >> n >> m >> k;
	d.resize(m);
	id.resize(n,-1);
	rep(i,m){
		cin >> d[i];
		d[i]--;
		id[d[i]] = i;
	}
	v.resize(n);
	rep(i,n){
		v[i].resize(k);
		rep(j,k){
			cin >> v[i][j];
			v[i][j]--;
		}
	}
	cout << solve() << endl;
}
