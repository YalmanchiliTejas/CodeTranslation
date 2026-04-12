#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
using namespace std;
using llong = long long;
using vi    = vector<int>;
using vvi   = vector<vi >;
using vvvi  = vector<vvi >;
using pii   = pair<int,int>;
constexpr int    INF=1e9;
constexpr double EPS=1e-9;
constexpr int    MOD=1e9+7;
template<class Type>
void line(const Type &a){int cnt=0;for(const auto &elem:a){cerr<<(cnt++?' ':'>');cerr<<elem;}cerr<<endl;}

using vl   = vector<long long>;
using vvl  = vector<vl >;
using vvvl = vector<vvl >;

int main(){
	llong n;
	int x,m;
	cin>>n>>x>>m;
	
	vi next(m);
	REP(i,m) next[i]=(llong)i*i%m;
	line(next);
	
	int p=x;
	vl v;
	vi seen(m,-1);
	for(int i=0;;++i){
		v.push_back(p);
		seen[p]=i;
		
		p=next[p];
		if(seen[p]>=0) break;
	}
	for(int i=1;i<v.size();++i) v[i]+=v[i-1];
	line(v);
	
	llong ans=0LL;
	if(n<=v.size()) ans+=v[n-1];
	else{
		if(seen[p]==0){
			int range=v.size();
			ans+=v[v.size()-1]*(n/range);
			if(n%range) ans+=v[n%range-1];
		}else{
			ans+=v[seen[p]-1];
			n-=seen[p];
			int range=v.size()-seen[p];
			ans+=(v[v.size()-1]-v[seen[p]-1])*(n/range);
			if(n%range) ans+=v[seen[p]-1+(n%range)]-v[seen[p]-1];
		}
	}
	
	cout<<ans<<endl;
	return 0;
}