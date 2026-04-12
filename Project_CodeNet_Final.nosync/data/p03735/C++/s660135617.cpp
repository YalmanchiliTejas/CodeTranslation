#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a<b)?(a=b,1):0;}
template<class T>bool chmin(T &a, const T &b) { return (b<a)?(a=b,1):0;}

using ll=long long;
using R=long double;
const R EPS=1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r){return(r > EPS)-(r < -EPS);}
inline R sq(R x){return sqrt(max(x,0.0L));}

const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

// Problem Specific Parameter:

#define error(args...) { vector<string> _debug = split(#args, ',');err(begin(_debug), args);}

vector<string> split(const string& s, char c){
	vector<string> v;stringstream ss(s);string x;
	while (getline(ss, x, c)) v.emplace_back(x);
	return move(v);
}

void err(vector<string>::iterator it) {cerr << endl;}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a,Args... args){
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << " ",err(++it, args...);
}

const ll limit=200010;
ll x[limit],y[limit];

int main(void){
	ll n;
	cin >> n;
	rep(i,n) cin >> x[i] >> y[i];

	ll cmin=1LL<<60,cmax=-1,tmin,tmax;

	rep(i,n){
		if(chmin(cmin,min(x[i],y[i]))){
			tmin = x[i]^y[i]^cmin;
		}
		
		if(chmax(cmax,max(x[i],y[i]))){
			tmax = x[i]^y[i]^cmax;
		}
	}

	
	ll ans=1LL<<60;

	{
		ll rmin=cmin,rmax=tmax,bmin=tmin,bmax=cmax;
		
		// diff
		rep(i,n){
			ll r=x[i],b=y[i];
			if(r>b) swap(r,b);
			chmax(rmax,r);
			chmin(bmin,b);
		}

		//error("diff",rmin,rmax,bmin,bmax);

		chmin(ans,1LL*(rmax-rmin)*(bmax-bmin));
	}

	{
		ll rmin=cmin,rmax=cmax,bmin=min(tmin,tmax),bmax=max(tmin,tmax);
		// same
		
		using pii=pair<ll,ll>;
		vector<pii> ary;

		rep(i,n){
			ll r=x[i],b=y[i];
			if(bmin <= r and r <= bmax) continue;
			if(bmin <= b and b <= bmax) continue;

			if(bmax < r and bmax < b) chmax(bmax,min(r,b));			
			if(r < bmin and b < bmin) chmin(bmin,max(r,b));
		}

		rep(i,n){
			ll r=x[i],b=y[i];
			if(bmin <= r and r <= bmax) continue;
			if(bmin <= b and b <= bmax) continue;
			if(r>b) swap(r,b);
			ary.push_back(pii(bmin-r,b-bmax));
		}
		
		sort(begin(ary),end(ary));
		const ll m=ary.size();

		if(m>0){
			ll len=ary[m-1].second,add=ary[m-1].first;
			
			rrep(i,m-2){
				if(ary[i].first != ary[i+1].first) chmin(add,ary[i].first+len);
				chmax(len,ary[i].second);
			}

			chmin(add,len);
			bmax += add;
		}

		//error("same",rmin,rmax,bmin,bmax);

		chmin(ans,1LL*(rmax-rmin)*(bmax-bmin));
	}

	cout << ans << endl;
	return 0;
}