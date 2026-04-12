#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define int long long
#define ieps (int) 1e6
#define eps (int) 1e9
#define pii pair<int, int>
int pai[ieps] , peso[ieps];

struct edge{
	int x , y , w;
};

int fd(int x){
	return pai[x] == x ? x : pai[x] = fd(pai[x]);
}

void join(int u , int v){
	u = fd(u) , v = fd(v);
	if(peso[u] < peso[v]) swap(u , v);
	pai[v] = u , peso[u]++;
}

bool cmp(edge a , edge b){
	return a.w < b.w;
}


int32_t main(){
	int n;
	cin>>n;
	vector<pair<pii , int> > v(n) , v3(n);
	for(int i = 0;i<n;i++){
		cin>>v[i].F.F>>v[i].F.S;
		v[i].S = i;
		v3[i].F.F = v[i].F.S;
		v3[i].F.S = v[i].F.F;
		v3[i].S  = i;
		pai[i] = i , peso[i] = 0;
	}
	sort(v.begin() , v.end());
	sort(v3.begin() , v3.end());
	int resp = 0;
	vector<edge> vet;
	set<pii> builded;
	for(int i = 0;i<n-1;i++){
		int v1 = abs(v[i+1].F.F - v[i].F.F) , v2 = abs(v[i+1].F.S - v[i].F.S);
		vet.pb({v[i].S , v[i+1].S , min(v1, v2)});
		v1 = abs(v3[i+1].F.F - v3[i].F.F) , v2 = abs(v3[i+1].F.S - v3[i].F.S);
		vet.pb({v3[i].S , v3[i+1].S , min(v1 , v2)});
	}
	sort(vet.begin(), vet.end() , cmp);
	for(int i = 0;i<vet.size();i++){
		if(fd(vet[i].x) != fd(vet[i].y)){
			join(vet[i].x , vet[i].y);
			resp+=vet[i].w;
		}
	}
	cout<<resp;
}