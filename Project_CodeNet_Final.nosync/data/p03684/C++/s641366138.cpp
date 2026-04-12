#include<bits/stdc++.h>
#define LL long long
#define MAXN 100005
using namespace std;


int N,M;
int x[MAXN], y[MAXN];

struct Node{
	int id,v;
	Node(int id=0, int v=0):id(id), v(v){}
	
	bool operator < (const Node& n1) const{
		return v < n1.v;
	}
} nx[MAXN], ny[MAXN];


struct edge{
	int u,v,w;
	edge(int u=0, int v=0, int w=0):u(u), v(v), w(w){}
	
	bool operator < (const edge& e1) const{
		return w < e1.w;
	}
} e[2*MAXN];

void addE(int u, int v, int w){
	e[++M] = edge(u,v,w);
	//cout<<"addE: "<<u<<" "<<v<<" "<<w<<endl;
}

int p[MAXN];
int findR(int x){
	if(x==p[x]) return x;
	else return p[x] = findR(p[x]);
}

LL ans = 0;
void kruskal(){
	for(int i=1;i<=N;i++) p[i] = i;
	sort(e+1, e+1+M);
	
	int u,v,w,ru,rv;
	for(int i=1;i<=M;i++){
		u = e[i].u; v = e[i].v;
		ru = findR(u);
		rv = findR(v);
		if(ru==rv) continue;
		
		ans += e[i].w;
		p[ru] = rv;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>x[i]>>y[i];
		nx[i] = Node(i, x[i]);
		ny[i] = Node(i, y[i]);
	}

	sort(nx+1, nx+1+N);
	sort(ny+1, ny+1+N);

	for(int i=1;i<N;i++){
		addE(nx[i].id, nx[i+1].id, nx[i+1].v - nx[i].v);
		addE(ny[i].id, ny[i+1].id, ny[i+1].v - ny[i].v);
	}
	
	kruskal();
	
	cout<<ans<<endl;
	
	return 0;
}
