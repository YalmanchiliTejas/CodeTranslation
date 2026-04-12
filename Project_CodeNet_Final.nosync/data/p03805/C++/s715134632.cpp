#define debug_interval ','
#define dump_interval ' '
#define debug_toggle 1
//{
#include<bits/stdc++.h>
using namespace std;
#define hi cerr<<"hi"<<endl;
#define int long long
#define INT_MAX LLONG_MAX
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define fi first
#define se second
#define mp make_pair
#define rev reverse
#define dans dump(ans)
#define MOD 1000000007
#define amp(v,n) (v).count(n)?v[n]++:v[n]=1
#define sysp system("pause")
#define PI acos(-1)
#define pf push_front

//{
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
template<class...A> inline void dump(){cout<<endl;}
template<class...A> inline void dump_rest() {cout<<endl;}
template<class T, class...A> inline void dump_rest(const T& first, const A&... rest){cout<<dump_interval<<first;dump_rest(rest...);}
template<class T,class...A> inline void dump(const T&first,const A&...rest){cout<<first;dump_rest(rest...);}
template<class...A> inline void debug(){cerr<<endl;}
template<class...A> inline void debug_rest() {cerr<<endl;}
template<class T, class...A> inline void debug_rest(const T& first, const A&... rest){cerr<<debug_interval<<first;debug_rest(rest...);}
template<class T,class...A> inline void debug(const T&first,const A&...rest){if(debug_toggle)cerr<<first,debug_rest(rest...);}
//}

typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}
template<int m>class mint{private:int i;public:mint() : i(0){}mint(int i): i((i%m+m)%m){}mint operator+(const mint& o){return o.i+i;}mint operator*(const mint& o){return o.i*i;}mint operator-(){return -i;}operator int() {return i;}};

int n,m,ans;
//vector<set<int> > g;
set<int> g[10];

main(){
	cin>>n>>m;
	rep(i,m){
		int a,b;
		cin>>a>>b;
		g[a].insert(b);
		g[b].insert(a);
	}
	vint v;
	rep(i,n)v.pb(i+1);
	do{
		if(v[0]!=1)break;
		bool flg=1;
		for(int i=0;i<n-1;i++){
			if(g[v[i]].count(v[i+1])==0){
				flg=0;
				break;
			}
		}
		if(flg)ans++;
	}while(next_permutation(all(v)));
	dans;
}

