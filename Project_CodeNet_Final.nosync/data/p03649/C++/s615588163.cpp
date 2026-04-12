#include "bits/stdc++.h"
#define esc(ret) cout << (ret) << endl,quick_exit(0)
#define fcout(d) cout << fixed << setprecision(d)
#define repU(i,s,t) for(int i = (int)(s); i <= (int)(t); ++i)
#define repD(i,s,t) for(int i = (int)(s); i >= (int)(t); --i)
#define rep(i,n) repU(i,0,n - 1)
#define rep1(i,n) repU(i,1,n)
#define all(v) begin(v),end(v)
#define vct vector
#define prique priority_queue
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define qceil(n,d) ((n) > 0 ? ((n) - 1) / (d) + 1 : (n) / (d))
#define parity(a,b) ((a) & 1 == (b) & 1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const pii dir[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int mod = 1e9 + 7;
const int inf32 = (1 << 30) - 1;
const ll inf64 = (1LL << 62) - 1;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	ll N; cin >> N;
	ll tmp,N2 = N;
	prique<ll> que;
	rep(i,N){
		cin >> tmp; que.push(tmp);
	}
	while((tmp = que.top()) >= N2){
		que.pop();
		ll d = (tmp - N2) / N + 1;
		//cout << tmp << ' ' << d << endl;
		que.push(tmp - d * (N + 1));
		N2 -= d;
	}
	esc(N - N2);
}

