#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int S, T;
int U[200010], V[200010], DD[200010];
int vis[100010];
vector<vector<int> > G(100010);
vector<vector<int> > G2(100010);
struct data{
	long long leng;
	int to;
	long long num;
};
struct cmp {
	bool operator() (const struct data a, const struct data b) const {
		if(a.leng > b.leng)
			return true;
		else if(a.leng < b.leng)
			return false;
		else{
			if(a.to > b.to)
				return true;
			else
				return false;
		}
	}
};
priority_queue<struct data, vector<struct data>, cmp > pq;
int s, t;
long long D = 1000000007;
long long len;
long long L1[100010];
long long L2[100010];
long long Num1[100010];
long long Num2[100010];
long long Val[200010];
int VL;

void solve()
{
	int i, j;
	s = S;
	t = T;
	struct data d, d2;
	d.leng = 0;	
	d.to = s;
	d.num = 1;
	Num1[s] = 1;
	pq.push(d) ;
	int u, v;
	long long tl;
	long long tmp;
	while(!pq.empty() ){
		d = pq.top();
		u = d.to;
		if(vis[u]==1){
			pq.pop();
			continue;
		}
		vis[u] = 1;
		if(u == t){
			len = d.leng ;
			break;
		}
		tl = d.leng ;
		tmp = 0;
		while(d.to == u && d.leng==tl){
			tmp += d.num;
			tmp %= D;
			pq.pop() ;
			if(pq.empty() )
				break;
			d = pq.top();
		}
		//L1[u] = d.leng ;
		L1[u] = tl;
		Num1[u] = tmp;
		for(i=0; i<G[u].size(); i++){
			v = G[u][i];
			if(vis[v]==0){
				d2.leng = tl + G2[u][i];
				d2.to = v;
				d2.num = tmp;
				pq.push(d2) ;
			}
		}
	}
	while(!pq.empty() )
		pq.pop() ;
	
	for(i=0; i<N; i++)
		vis[i] = 0;
	s = T;
	t = S;
	d.leng = 0;	
	d.to = s;
	d.num = 1;
	Num2[s] = 1;
	pq.push(d) ;
	while(!pq.empty() ){
		d = pq.top();
		u = d.to;
		if(vis[u]==1){
			pq.pop();
			continue;
		}
		vis[u] = 1;
		tl = d.leng ;
		tmp = 0;
		while(d.to == u && d.leng==tl){
			tmp += d.num;
			tmp %= D;
			pq.pop() ;
			if(pq.empty() )
				break;
			d = pq.top();
		}
		Num2[u] = tmp;
		L2[u] = tl;
		if(u == t){
			break;
		}
		for(i=0; i<G[u].size(); i++){
			v = G[u][i];
			if(vis[v]==0){
				d2.leng = tl + G2[u][i];
				d2.to = v;
				d2.num = tmp;
				pq.push(d2) ;
			}
		}
	}
	while(!pq.empty() )
		pq.pop() ;
	
	VL = 0;
	for(i=0; i<N; i++){
		if(L1[i]<len/2 || (L1[i]==len/2&&len%2==1) ){
			for(j=0; j<G[i].size(); j++){
				v = G[i][j];
				if(L2[v]<len/2 || (L2[i]==len/2&&len%2==1) ){
					if(L1[i]+L2[v]+G2[i][j]==len){
						Val[VL] = Num1[i] * Num2[v];
						Val[VL] %= D;
						VL ++;
					}
				}
			}
		}
		else if(L1[i]==len/2 && len%2==0){
			if(L1[i]+L2[i]==len){
				Val[VL] = Num1[i] * Num2[i];
				Val[VL] %= D;
				VL ++;
			}
		}
	}
	long long sum = 0;
	for(i=0; i<VL; i++){
		sum += Val[i];
		sum %= D;
	}
	long long res=0;
	for(i=0; i<VL; i++){
		tmp = sum+D-Val[i];
		tmp %= D;
		tmp *= Val[i];
		tmp %= D;
		res += tmp;
		res %= D;
	}
	printf("%lld\n", res);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int i;
	scanf("%d%d", &N, &M);
	scanf("%d%d", &S, &T);
	S--, T--;
	for(i=0; i<M; i++){
		scanf("%d%d%d", &U[i], &V[i], &DD[i]);
		U[i]--, V[i]--;
		G[U[i]].push_back(V[i]);
		G[V[i]].push_back(U[i]);
		G2[U[i]].push_back(DD[i]);
		G2[V[i]].push_back(DD[i]);
	}
	solve();
	return 0;
}