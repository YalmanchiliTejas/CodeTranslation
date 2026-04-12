#include <bits/stdc++.h>

/*.....DEFINITIONS...... */
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define T() int tt; cin>>tt; while(tt--)
#define mp make_pair
#define pb push_back
#define lchild (2*node+1)
#define rchild (2*node+2)
#define f first
#define s second
#define br cout<<"\n"
#define MOD (1000000007LL)
#define all(v) (v).begin(), (v).end()
#define eps 1e6
#define sll(n) scanf("%lld", &n);
#define si(n) scanf("%d", &n);
#define what_is(x) cerr << #x << " is " << x << "\n";

using namespace std;

/*.....TYPEDEFS ....*/
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

/*....USEFUL FUNCTIONS....*/
ll pwr(ll base, ll exp, ll mod=MOD){ll res=1; while(exp>0){if(exp%2){res=(res*base)%mod;}base=(base*base)%mod;exp/=2;}return res;}
ll gcd(ll a, ll b){ if(b==0)return a; else gcd(b, a%b);}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if (n%2==0||n%3==0)return false;for(int i=5; i*i<=n; i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}

/*---------Solution below this line --------*/

const int N = 1234567;

int n;
long long x, y, c1, c2;
vector<pair<pii,int> > v;
int p[N];
vector<pair<ll, pii> >all;  

int root(int a){
	while(p[a]!=a){
		p[a] = p[p[a]];
		a = p[a];
	}
	return a;
}

void un(int x, int y){
	int a = root(x);
	int b = root(y);
	p[a] = p[b];
}



int main(){
	//FIO
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d %d", &x, &y);
		v.push_back({{x,y},i});
		p[i] = i;
	}
	
	sort(all(v));
	for(int i=0; i<n-1; ++i){
		c1 = abs(v[i].first.first - v[i+1].first.first);
		c2 = abs(v[i].first.second - v[i+1].first.second);
		all.push_back({c1,{v[i].second, v[i+1].second}});
		all.push_back({c2,{v[i].second, v[i+1].second}});
	}
	
	sort(all(v), [&](pair<pii,int> left, pair<pii,int> right){
		return left.first.second < right.first.second;	
	});
	
	for(int i=0; i<n-1; ++i){
		c1 = abs(v[i].first.first - v[i+1].first.first);
		c2 = abs(v[i].first.second - v[i+1].first.second);
		all.push_back({c1,{v[i].second, v[i+1].second}});
		all.push_back({c2,{v[i].second, v[i+1].second}});
	}
	
	sort(all(all));
	
	long long res = 0;
	for(int i=0; i<all.size(); ++i){
		x = all[i].second.first;
		y = all[i].second.second;
		long long cost = all[i].first;
		if(root(x)!=root(y)){
			res += cost;
			un(x,y);
		}
	}
	
	printf("%lld\n", res);
	
	
	
		
	
return 0;
}
