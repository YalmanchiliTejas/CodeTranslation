#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(a, b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define show(x) cout <<#x<<" = "<<(x)<<endl
#define spair(p) cout <<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout <<" "<<kbrni;cout<<endl

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 10005;

struct edge
{
	int to,cost;
};

vector<edge> G[MAX_N];

void dist(int u,vector<int>& vec)
{
	queue<int> que;
	que.push(u);
	vec[u] = 0;
	while(!que.empty()){
		int v = que.front();
		que.pop();
		rep(i,G[v].size()){
			if(vec[G[v][i].to] > vec[v]+G[v][i].cost){
				vec[G[v][i].to] = vec[v]+G[v][i].cost;
				que.push(G[v][i].to);
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	rep(i,n-1){
		int x,y,z;
		cin >> x >> y >> z;
		G[x].push_back((edge){y,z});
		G[y].push_back((edge){x,z});
	}
	vector<int> v1(n,INF),v2(n,INF),v3(n,INF);
	dist(0,v1);
	int x = max_element(all(v1)) - v1.begin();
	dist(x,v2);
	int y = max_element(all(v2)) - v2.begin();
	dist(y,v3);
	rep(i,n){
		cout << max(v2[i],v3[i]) << "\n";
	}
	return 0;
}