#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N (100001)
#define M (200001)

struct edge{
	int to;
	long long dis;
	int num;
};

struct edge2{
	int fe;
	int te;
	long long de;
};

int n, m;
vector<edge>e[N];
vector<edge2>ee;
long long ed1[M];
long long ed2[M];
long long cs[M];
long long ct[M];
int sside[M];
long long d[N];
bool dec[N];
long long ss1;
long long ss2;
long long kk1;
long long kk2;


void init(void){
	f(i, N){
		d[i] = 1000000000000000009;
		dec[i] = false;
	}
}

void dijkstra(int s){
	d[s] = 0;
	cs[s] = 1;
	priority_queue<pair<long long, int> >pq;
	pq.push(make_pair(0, s));
	while (!pq.empty()){
		while (dec[pq.top().second]){
			pq.pop();
			if (pq.empty())return;
		}
		dec[pq.top().second] = true;
		f(i, e[pq.top().second].size()){
			if (ed1[e[pq.top().second][i].num] == -1){
				ed1[e[pq.top().second][i].num] = d[pq.top().second];
				sside[e[pq.top().second][i].num] = pq.top().second;
			}
			if (d[e[pq.top().second][i].to] > (d[pq.top().second] + e[pq.top().second][i].dis)){
				d[e[pq.top().second][i].to] = d[pq.top().second] + e[pq.top().second][i].dis;
				pq.push(make_pair(-d[e[pq.top().second][i].to], e[pq.top().second][i].to));
				cs[e[pq.top().second][i].to] = cs[pq.top().second];
			}
			else if (d[e[pq.top().second][i].to] == (d[pq.top().second] + e[pq.top().second][i].dis)){
				cs[e[pq.top().second][i].to] += cs[pq.top().second];
				cs[e[pq.top().second][i].to] = cs[e[pq.top().second][i].to] % MOD;
			}
		}
	}
	return;
}

void dijkstra2(int s){
	d[s] = 0;
	ct[s] = 1;
	priority_queue<pair<long long, int> >pq;
	pq.push(make_pair(0, s));
	while (!pq.empty()){
		while (dec[pq.top().second]){
			pq.pop();
			if (pq.empty())return;
		}
		dec[pq.top().second] = true;
		f(i, e[pq.top().second].size()){
			if (ed2[e[pq.top().second][i].num] == -1)ed2[e[pq.top().second][i].num] = d[pq.top().second];
			if (d[e[pq.top().second][i].to] > (d[pq.top().second] + e[pq.top().second][i].dis)){
				d[e[pq.top().second][i].to] = d[pq.top().second] + e[pq.top().second][i].dis;
				pq.push(make_pair(-d[e[pq.top().second][i].to], e[pq.top().second][i].to));
				ct[e[pq.top().second][i].to] = ct[pq.top().second];
			}
			else if (d[e[pq.top().second][i].to] == (d[pq.top().second] + e[pq.top().second][i].dis)){
				ct[e[pq.top().second][i].to] += ct[pq.top().second];
				ct[e[pq.top().second][i].to] = ct[e[pq.top().second][i].to] % MOD;
			}
		}
	}
	return;
}


int main(void){
	int x, y;
	int s, t;
	long long z;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t);
	s--;
	t--;
	init();
	f(i, m){
		scanf("%d %d %lld", &x, &y, &z);
		x--;
		y--;
		e[x].push_back({ y, 2 * z, i });
		e[y].push_back({ x, 2 * z, i });
		if (x > y)swap(x, y);
		ee.push_back({ x, y, 2 * z });
		ed1[i] = -1;
		ed2[i] = -1;
		cs[i] = 1;
		ct[i] = 1;
	}
	dijkstra(s);
	long long dd = d[t];
	dd = dd / 2;
	init();
	dijkstra2(t);
	ss1 = 0;
	ss2 = 0;
	f(i, n){
		if (d[i] == dd){
			kk1 = cs[i] * ct[i];
			kk1 = kk1%MOD;
			ss1 += kk1;
			ss1 = ss1%MOD;
			kk1 = kk1*kk1;
			kk1 = kk1%MOD;
			ss2 += kk1;
			ss2 = ss2%MOD;
		}
	}
	f(i, m){
		if ((ed1[i] + ed2[i] + ee[i].de) == (2 * dd)){
			if (ed1[i] <dd&&ed2[i] < dd){
				if (ee[i].fe == sside[i]){
					kk1 = cs[ee[i].fe] * ct[ee[i].te];
					kk1 = kk1%MOD;
					ss1 += kk1;
					ss1 = ss1%MOD;
					kk1 = kk1*kk1;
					kk1 = kk1%MOD;
					ss2 += kk1;
					ss2 = ss2%MOD;
				}
				else{
					kk1 = cs[ee[i].te] * ct[ee[i].fe];
					kk1 = kk1%MOD;
					ss1 += kk1;
					ss1 = ss1%MOD;
					kk1 = kk1*kk1;
					kk1 = kk1%MOD;
					ss2 += kk1;
					ss2 = ss2%MOD;
				}
			}
		}
	}
	long long ans = (ss1*ss1);
	ans = ans%MOD;
	ans += MOD;
	ans -= ss2;
	ans = ans%MOD;
	printf("%lld\n", ans);
	return 0;
}
