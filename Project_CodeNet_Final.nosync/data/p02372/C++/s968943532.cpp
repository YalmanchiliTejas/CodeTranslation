#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define P pair<ll,ll>
#define FOR(I,A,B) for(ll I = int(A); I < int(B); ++I)
#define FORR(I,A,B) for(ll I = int((B)-1); I >= int(A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //xi>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //xi>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define REV(x) (reverse(x.begin(),x.end())) //reverse
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;
// 木の直径の端点までの距離の大きい方？
class dijkstra{ 
//0indexed 
public: 
	int v,startv; 
	vector<int> d; 
	vector<vector<pair<int,int> > >e; 
	dijkstra(int n0){
		initsize(n0);
	}
	void initsize(int n0){ 
		d.resize(n0); 
		for(int i=0;i<n0;i++)d[i]=INT_MAX; 
		vector<pair<int,int> > ep; 
		for(int i=0;i<n0;i++)e.push_back(ep); 
		v=n0; 
	} 
	void initstart(int s){ 
		startv=s;
		d[s]=0;
	}
	void make_edge(int x,int y,int cost){ 
		e[x].push_back(make_pair(y,cost)); 
		e[y].push_back(make_pair(x,cost)); 
	}
	void make_edgedir(int x,int y,int cost){ 
		e[x].push_back(make_pair(y,cost)); 
	}
	void calcdistance(int st){
		initstart(st); 
		// <-cost,x> 
		//cost startv->x 
		priority_queue<pair<int,int> > q; 
		pair<int,int> p; 
		vector<bool> did; 
		for(int i=0;i<v;i++)did.push_back(false); 
		did[startv]=true; 
		for(int i=0;i<int(e[startv].size());i++){ 
			p.first=-e[startv][i].second; 
			p.second=e[startv][i].first; 
			q.push(p); 
		}
		while(q.size()!=0){
			pair<int,int> p;
			p=q.top();
			q.pop();
			int x,costsx;
			x=p.second;
			costsx=-p.first;
			if(did[x]==true)continue;
			did[x]=true;
			d[x]=costsx;
			for(int i=0;i<int(e[x].size());i++){
				p.first=-(d[x]+e[x][i].second);
				p.second=e[x][i].first;
				if(did[p.second]==false)q.push(p);
			}
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,a,b,w;
	cin >> n;
	if(n==1){
	    cout << 0 << endl;
	    return 0;
	}
	dijkstra d1(n),d2(n);
	FOR(i,0,n-1){
		cin >> a >> b >> w;
		d1.make_edge(a,b,w);
		d2.make_edge(a,b,w);
	}
	int v1,v2,len1=-1,len2=-1;
	d1.calcdistance(0);
	FOR(i,1,n){
		if(d1.d[i]>len1){
			len1 = d1.d[i];
			v1 = i;
		}
	}
	d1.calcdistance(v1);
	FOR(i,0,n){
		if(d1.d[i]>len2){
			len2 = d1.d[i];
			v2 = i;
		}
	}
	d2.calcdistance(v2);
	FOR(i,0,n){
		cout << max(d1.d[i],d2.d[i]) << endl;
	}
}

