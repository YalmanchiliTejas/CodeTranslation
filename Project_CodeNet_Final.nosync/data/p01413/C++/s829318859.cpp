#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int N, M, W, T;
map<string,int> f_item;
vector<pii> item;
vector<pii> pos;
vector<vector<pii> > sale;

vector<pii> item_set;

const ll INF = 1e15;

ll bitDP[1<<8][8];
ll solve_bitdp(int status, int now) {
	if(bitDP[status][now]+1)
		return bitDP[status][now];
	if(!status)
		return bitDP[status][now] = abs(pos[N].fi-pos[now].fi)
			+ abs(pos[N].se-pos[now].se);
	ll res = INF;
	for(int i = 0; i < N; i++) {
		if((status & (1 << i))) {
			ll cost;
			cost = abs(pos[i].fi-pos[now].fi) + abs(pos[i].se-pos[now].se);
			assert(cost < INF);
			res = min(res, solve_bitdp(status ^ (1 << i), i) + cost);
		}
	}
	return bitDP[status][now] = res;
}

ll dp[10100];
ll solve() {
	for(int i = 0; i < (1 << N); i++) {
		ll route, earn;
		route = solve_bitdp(i,N);
		memset(dp,0,sizeof(dp));
		for(int j = 0; j < N; j++) {
			if(i & (1 << j)) for(int k = 0; k < sale[j].size(); k++) {
				pii tmp;
				pii dpitem;
				tmp = item[sale[j][k].fi];
				dpitem = pii(tmp.fi, tmp.se-sale[j][k].se);
				for(int l = 0; l <= W; l++)
					if(0 <= l-dpitem.fi && l-dpitem.fi <= W)
						dp[l] = max(dp[l],dp[l-dpitem.fi]+dpitem.se);
			}
		}
		earn = dp[W];
		item_set.push_back(pll(route,earn));
		//cout << route << "," << earn << endl;
	}
	memset(dp,0,sizeof(dp));
	for(int i = 0; i < item_set.size(); i++) {
		for(int j = 0; j <= T; j++) {
			if(0 <= j-item_set[i].fi && j-item_set[i].fi <= T)
				dp[j] = max(dp[j], dp[j-item_set[i].fi] + item_set[i].se);
		}
	}
	return dp[T];
}

int main() {
	cin >> N >> M >> W >> T;
	for(int i = 0; i < M; i++) {
		string S;
		int V, P;
		cin >> S >> V >> P;
		f_item[S] = i;
		item.push_back(pii(V,P));
	}
	sale.resize(N);
	for(int i = 0; i < N; i++) {
		int L, X, Y;
		cin >> L >> X >> Y;
		pos.push_back(pii(X,Y));
		for(int j = 0; j < L; j++) {
			string R;
			int K;
			cin >> R >> K;
			sale[i].push_back(pii(f_item[R],K));
		}
	}
	pos.push_back(pii(0,0));
	memset(bitDP,-1,sizeof(bitDP));
	cout << solve() << endl;
}