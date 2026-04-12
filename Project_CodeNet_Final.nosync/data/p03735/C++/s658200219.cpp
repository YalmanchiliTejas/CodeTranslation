#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,P> P1;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
#define mp1(a,b,c) P1(a,P(b,c))

const ll INF=1000000000000000000;
const int dir_4[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const int dir_8[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

int main(){
	static ll n;
	static ll x[200010],y[200010];
	scanf("%lld",&n);
	rep(i,n)scanf("%lld%lld",&x[i],&y[i]);
	
	ll M=0,R=0,B=0;
	ll m=INF,r=INF,b=INF;
	rep(i,n){
		R = max( R , max(x[i],y[i]) );
		B = max( B , min(x[i],y[i]) );
		r = min( r , max(x[i],y[i]) );
		b = min( b , min(x[i],y[i]) );
	}
	M = R;
	m = b;
	
	ll ret = (R-r)*(B-b);
	
	priority_queue<P,vector<P>,greater<P>> que;
	rep(i,n){
		que.push(P(min(x[i],y[i]),max(x[i],y[i])));
	}
	while(1){
		P p = que.top(); que.pop();
		if(p.sc <= p.fr)break;
		que.push(P(p.sc,p.fr));
		B = max( B , p.sc );
		b = que.top().fr;
		ret = min( ret , (M-m)*(B-b) );
	}
	cout << ret << endl;
}

