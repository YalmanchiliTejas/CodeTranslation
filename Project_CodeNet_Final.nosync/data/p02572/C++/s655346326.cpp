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
//#pragma g++ optimize("O2")
//#pragma GCC target("avx,avx2,fma")
using namespace std;

#define endl '\n'
#define f(k,a,b) for(int k=(a);k<(b);++k)
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
#define all(x) x.begin(),x.end()
#define ret return
const int fix = (int)1e9 + 7;

int po2(lli a){double temp = a;if(log2(temp)==(int)log2(temp))return log2(temp);return -1;}
void tc(int i){cout<<"Case #"<<i+1<<": ";}
void yes(){cout<<"YES"<<endl;}
void no(){cout<<"NO"<<endl;}
void impb(){cout<<"IMPOSSIBLE"<<endl;}
int ct(){int t;scanf("%lld",&t);return t;}
int gcd(int a, int b) {if (b == 0)return a;return gcd(b, a % b);}
int pwr(int a, int b){ int x=1, y=a; while(b>0){if(b%2) x = (x*y)%fix; y=(y*y)%fix; b/=2;} return x;}
int power(int a, int b){ int x=1, y=a; while(b>0){if(b%2) x = (x*y); y=(y*y); b/=2;} return x;}
int pmodinv(int a){return pwr(a,fix-2);}
void error(){cerr<<"Here!"<<endl;}

vvi adj;


const int N = 1e6+5;
bool visited[N]= {};
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


int min(int a,int b){if(a<b)ret a;ret b;}
int max(int a, int b){if (a>b) ret a;ret b;}

vector <int> factorial((int)4002);

int nCr(int n, int k){
	if(n<k) ret 0;
	return (factorial[n]*((pmodinv(factorial[k])*pmodinv(factorial[n-k]))%fix))%fix;
}


/******************* -- DSU -- *******************/

vi dsu_par(N);
vi sze(N);

void make_set(int n){
	f(j,1,n+5){
		dsu_par[j]=j;
		//sze[j]=j;

	}
}

int find_set(int a){
	if(dsu_par[a]==a)
		return a;
	return dsu_par[a] = find_set(dsu_par[a]);
	// cost[a]+=dsu_par[a];
	//return dsu_par[a];
}

void union_set(int a, int b){
	a = find_set(a);
	    b = find_set(b);
	    if (a^b) {
	     //   if (sze[a] < sze[b])
	         //   swap(a, b);
	        dsu_par[b] = a;
	       //sze[a] += sze[b];
	        //sze[a] = sze[b];
	    }
}



/******************** LCA *********************/
map <pii, int> mp;
vvi up;
vi tin, tout;
int dfs_timer=0;
int lim;
int dist[N]={};
void _dfs(int v, int par){
	tin[v] = ++dfs_timer;
	up[v][0] = par;
	f(j,1,lim+1)
	up[v][j] = up[up[v][j-1]][j-1];

	for(int u:adj[v]){
		if(u^par){
			dist[u] = dist[v] + mp.find(pii(u,v))->second;
			//parent[u]=v;
			_dfs(u,v);
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



int32_t main() {

	int t=1;
		//t=ct();

		f(ii,0,t){

			/*int n=ct(),m=ct();
			//cin>>n>>m;
				make_set(n);
			f(j,0,m){
				char rec;
				int x;
				//cin>>rec>>x;
				//cin>>rec; x=ct();
				scanf("%c ", &rec);
				x=ct();
				if(rec=='-'){
					union_set(x+1,x);
				}else{
					int answer = find_set(x);
					if(answer>n)answer=-1;
					//cout<<answer<<endl;
					printf("%lld\n",answer);
				}
			}
*/
			int n=ct();
			vi arr(n);
			int sum = 0;
			int diff =0;
			f(j,0,n){
				cin>>arr[j];
				sum+=arr[j];
				sum%=fix;
				diff+=(arr[j]*arr[j]);
				diff%=fix;
			}
			sum*=sum;
			sum%=fix;
			cout<<((sum-diff+fix)*pmodinv(2))%fix<<endl;
		}
ret 0;
}

