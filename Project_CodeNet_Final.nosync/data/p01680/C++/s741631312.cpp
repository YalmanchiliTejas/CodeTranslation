#include <bits/stdc++.h>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

const int nmax=100010;
const ll mod=1000000007;
bool used[nmax];



ll power(ll a,ll n){
	ll b=1LL;
	while(n){
		if(n&1) b=b*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return b%mod;
}

int par[nmax],ranks[nmax],sz[nmax];

void init(int n){rep(i,n) par[i]=i,ranks[i]=sz[i]=0;}
int find(int x){return (x==par[x])?x:par[x]=find(par[x]);}
void unite(int a,int b){
	a=find(a),b=find(b);
	if(ranks[a]<ranks[b])
		par[a]=b;
	else{
		par[b]=a;
		if(ranks[a]==ranks[b]) ranks[a]++;
	}
	return ;
}
bool same(int a,int b){return find(a)==find(b);}


int main(void){
	int n,m;
	while(cin >> n >> m){
		if(n==0&&m==0) break;
		rep(i,n) used[i]=false;
		init(n);

		rep(i,m){
			int a,b;
			cin >> a >> b;
			a--,b--;
			unite(a,b);
		}

		rep(i,n) sz[find(i)]++;

		if(m==0)
			cout << power(2,n) << endl;
		else{
			ll ans=1LL,num=0,res=0;
			rep(i,n){
				if(sz[i]>=2)
					num++;
				if(sz[i]==1)
					res++;
			}
			ans*=power(2,res);
			ans%=mod;
			ans*=power(2,num);
			ans%=mod;
			ans=(ans+1)%mod;
			cout << ans << endl;
		}
	}
	return 0;
}