#include<bits/stdc++.h>
#define fr(i,n) for(int i=0;i<(n);++i)
#define foor(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,n) for(int i=(n);i--;)
#define roof(i,b,a) for(int i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define Sort(x) sort(all(x))
#define Reverse(x) reverse(all(x))
#define PQ priority_queue
#define print(x) cout<<(x)<<endl
using namespace std;            typedef vector<int>  vi;
typedef long long ll;           typedef vector< ll>  vl;
typedef unsigned long long ull; typedef vector<ull>  vu;
typedef double dbl;             typedef vector<dbl>  vd;
typedef string str;             typedef vector<str>  vs;
typedef pair<int,int>pii;       typedef vector<pii>vpii; typedef map<int,int>mii;
typedef pair< ll, ll>pll;       typedef vector<pll>vpll; typedef map< ll, ll>mll;
typedef pair<dbl,dbl>pdd;       typedef vector<pdd>vpdd; typedef map<dbl,dbl>mdd;
typedef pair<str,str>pss;       typedef vector<pss>vpss; typedef map<str,str>mss;
typedef pair< ll,int>pli;       typedef vector<pli>vpli; typedef map< ll,int>mli;
typedef pair<dbl,int>pdi;       typedef vector<pdi>vpdi; typedef map<dbl,int>mdi;
template<typename T>vector<T>&operator<<(vector<T>&v,const T t){v.push_back(t);return v;}
template<typename T>multiset<T>&operator<<(multiset<T>&m,const T t){m.insert(t);return m;}
template<typename T>set<T>&operator<<(set<T>&s,const T t){s.insert(t);return s;}
template<typename T,typename U>PQ<T,vector<T>,U>&operator<<(PQ<T,vector<T>,U>&q,const T t){q.push(t);return q;}
template<typename T,typename U>istream&operator>>(istream&s,pair<T,U>&p){return s>>p.first>>p.second;}
template<typename T>istream&operator>>(istream&s,vector<T>&v){fr(i,v.size()){s>>v[i];}return s;}
template<typename T,typename U>ostream&operator<<(ostream&s,const pair<T,U>p){return s<<p.first<<" "<<p.second;}
template<typename T>ostream&operator<<(ostream&s,const vector<T>v){for(auto a:v){s<<a<<endl;}return s;}
const int MD=1e9+7;
template<typename T,typename U>vector<pair<T,U>>dijkstra(const vector<vector<pair<T,U>>>E,const U s,const T inf){using P=pair<T,U>;vector<P>d;fr(i,E.size()){d<<P{inf,i};}PQ<P,vector<P>,greater<P>>pq;pq<<(d[s]=P{0,s});while(pq.size()){P a=pq.top();pq.pop();U v=a.second;if(d[v].first>=a.first){for(P e:E[v]){if(d[v].first+e.first<d[e.second].first){d[e.second]=P{d[v].first+e.first,v};pq<<P{d[v].first+e.first,e.second};}}}}return d;}
template<typename T,typename U>map<U,pair<T,U>>dijkstra(map<U,vector<pair<T,U>>>E,const U s,const T inf){using P=pair<T,U>;map<U,P>d;for(pair<U,vector<P>>e:E){d[e.first]=P{inf,e.first};}PQ<P,vector<P>,greater<P>>pq;pq<<(d[s]=P{0,s});while(pq.size()){P a=pq.top();pq.pop();U v=a.second;if(d[v].first>=a.first){for(P e:E[v]){if(d[v].first+e.first<d[e.second].first){d[e.second]=P{d[v].first+e.first,v};pq<<P{d[v].first+e.first,e.second};}}}}return d;}
template<typename T>T max(const vector<T>a){T m=a[0];for(T e:a){m=max(m,e);}return m;}
template<typename T>T min(const vector<T>a){T m=a[0];for(T e:a){m=min(m,e);}return m;}
template<typename T>T gcd(const T a,const T b){return a?gcd(b%a,a):b;}
template<typename T>T gcd(const vector<T>a){T g=a[0];for(T e:a){g=gcd(g,e);}return g;}
ll pow(const ll a,const ll n,const int m){ll t;return n?(n&1?a>=0?a%m:~-m+~a%m:1)*(t=pow(a,n>>1,m),t*t%m)%m:1;}
ll C2(const int n){return(ll)n*~-n/2;}
ll sum(const vi a){ll s=0;for(int e:a){s+=e;}return s;}
ll sum(const vl a){ll s=0;for(ll e:a){s+=e;}return s;}
// (int) * (int) => (int)
// (int) / (int) => (int)

vpll fact(int n,int p){
	vpll v(n+1);
	v[0].first=1;
	foor(i,1,n){
		v[i].first=v[i-1].first*i%p;
	}
	v[n].second=pow(v[n].first,p-2,p);
	roof(i,n,1){
		v[i-1].second=v[i].second*i%p;
	}
	return v;
}

ll d[1001][1001];
main(){cin.tie(0);ios::sync_with_stdio(false);
	ll N,A,B,C,D;
	cin>>N>>A>>B>>C>>D;
	vpll f=fact(N,MD);
	d[A-1][0]=1;
	foor(i,A,B){
		foor(j,0,N){
			for(int k=0;k<=D;k?++k:(k=C)){
				if(j+i*k>N)break;
				d[i][j+i*k]+=d[i-1][j]*pow(f[i].second,k,MD)%MD*f[k].second%MD;
				d[i][j+i*k]%=MD;
			}
		}
	}
	print(d[B][N]*f[N].first%MD);
}
