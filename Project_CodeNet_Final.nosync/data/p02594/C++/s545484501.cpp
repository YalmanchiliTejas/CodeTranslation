//God's Grace
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include <stack>
#include <cstdio>
#include <fstream>
#include <climits>
#include <set>
#include <vector>
#include <tuple>
#include <cstring>
#include <functional>
#include <utility>
#include <iomanip>

using namespace std;

#define endl '\n'
#define f(k,a,b) for(int k=(a);k<(b);k++)
#define vi vector <int>
#define vvi vector <vector <int> >
#define vii vector <pair <int, int > >
#define int long long
#define lli long long
#define pii pair <int,int>
#define piii pair< pair<lli,lli>, lli >
#define fsd fflush(stdout);
#define pb(x) push_back(x)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//#define tdef typedef
#define ret return
const int fix = (int)1e9 + 7;

int po2(lli a){double temp = a;if(log2(temp)==(int)log2(temp))return log2(temp);return -1;}
void tc(int i){cout<<"Case #"<<i+1<<": ";}
void yes(){cout<<"YES"<<endl;}
void no(){cout<<"NO"<<endl;}
void impb(){cout<<"IMPOSSIBLE"<<endl;}
//int ct(){int t;scanf("%lld",&t);return t;}
int gcd(int a, int b) {if (b == 0)return a;return gcd(b, a % b);}
int pwr(int a, int b){ int x=1, y=a; while(b>0){if(b%2) x = (x*y)%fix; y=(y*y)%fix; b/=2;} return x;}
int pmodinv(int a){return pwr(a,fix-2);}


/*
lli modinv(lli a, lli m){
	lli m0 = m;
	lli y = 0, x = 1;

	    if (m == 1)
	      return 0;

	    while (a > 1)
	    {
	        // q is quotient
	       lli q = a / m;
	       lli t = m;

	        // m is remainder now, process same as
	        // Euclid's algo
	        m = a % m, a = t;
	        t = y;

	        // Update y and x
	        y = x - q * y;
	        x = t;
	    }

	    // Make x positive
	    if (x < 0)
	       x += m0;

	    return x;

}

*/



//int arr[(int)5e5+5];
const int N = 5e5+5;
list <int> adj[N];
queue <int> q;

int comanc(int u, int v,int parent[]){
	while(u^v){
		if(u==1||v==1)
			return 1;
		u = parent[u];
		v = parent[v];
	}

	return u;
}
int x;

int max(int a, int b){
	if (a>b)
		return a;
	return b;
}

vector <int> factorial((int)4002);

int nCr(int n, int k){
	return (factorial[n]*((pmodinv(factorial[k])*pmodinv(factorial[n-k]))%fix))%fix;
}


/********************* -- DSU -- *********************/
int dsu_par[N];
//int size[N];
void make_set(int n){
	f(j,1,n+1){
		dsu_par[j]=j;
		//size[j]=1;
	}
}

int find_set(int a){
	if(dsu_par[a]==a)
		return a;
	return dsu_par[a] = find_set(dsu_par[a]);
}

void union_set(int a, int b){
	a = find_set(a);
	    b = find_set(b);
	    if (a^b) {
	       // if (size[a] < size[b])
	            swap(a, b);
	        dsu_par[b] = a;
	      //  size[a] += size[b];

	    }
}
map <pii, int> mp;
vvi up;
vi tin, tout;
int dfs_timer=0;
int lim;
int dist[N]={};
void dfs(int v, int par){
	tin[v] = ++dfs_timer;
	up[v][0] = par;
	f(j,1,lim+1)
	up[v][j] = up[up[v][j-1]][j-1];

	for(int u:adj[v]){
		if(u^par){
			dist[u] = dist[v] + mp.find(pii(u,v))->second;
			//parent[u]=v;
			dfs(u,v);
		}
	}

	tout[v] = ++dfs_timer;
}

bool is_anc(int u, int v){ return tin[u] <= tin[v] && tout[u] >= tout[v];}
int lca(int u, int v){
	if(is_anc(u,v))
		return u;
	if(is_anc(v,u))
		return v;
	for(int i=lim;i>=0;i--)
		if(is_anc(up[u][i],v)^1)
			u = up[u][i];

	return up[u][0];
}


//Binary lifting method

/*
 * memset(dist,0,sizeof(dist));
		memset(parent,0,sizeof(parent));
		int n,m,q;
		cin>>n;
		tin.resize(n), tout.resize(n);
		adj.resize(n);
		lim = ceil(log2(n));
		up.assign(n,vi(lim+1));
		f(j,0,n-1){
			int a, b, c;
			cin>>a>>b>>c;a--,b--;
			adj[a].pb(b);
			adj[b].pb(a);
			mp.insert(piii(pii(a,b),c));
			mp.insert(piii(pii(b,a),c));
		}

		string rec;cin>>rec;
		dist[0]=0;
		dfs(0,0);
		while(rec!="DONE"){
			int a, b, k;
			if(rec=="DIST"){
				cin>>a>>b;
				a--,b--;
				cout<<abs(dist[a]-dist[lca(a,b)]+dist[b]-dist[lca(a,b)])<<endl;
			}else{
				cin>>a>>b>>k;
				a--,b--;

				int stop = lca(a,b);

				int ptr=a;
				int cnt=1;
				while(ptr!=stop&&cnt<k){
					ptr = parent[ptr];
					cnt++;
				}
				if(cnt==k)
					cout<<ptr+1<<endl;
				else
				{


						vector <int> v;
						ptr=b;
						while(ptr!=stop){
							v.pb(ptr);
							ptr = parent[ptr];
						}
						reverse(v.begin(),v.end());
						cout<<v[k-cnt-1]+1<<endl;

				}

			}
			cin>>rec;
		}


		cout<<endl;
		mp.clear();
 *
 */



int32_t main() {

	int t=1;
	//cin>>t;
	f(ii,0,t){
		int n;
		cin>>n;
		if(n>=30){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}

	ret 0;
}
