#include <bits/stdc++.h> 

using namespace std;

#define fcout(d) cout << fixed << setprecision(d)
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define rep1(i,n) for(int (i) = 1; (i) <= (n); ++(i))
#define repU(i,bottom,ceiling) for(auto (i) = (bottom); (i) <= (ceiling); ++(i))
#define repD(i,ceiling,bottom) for(auto (i) = (ceiling); (i) >= (bottom); --(i))
#define repV(i,v) for(auto (i) = begin(v); (i) < end(v); ++(i))
#define all(v)  begin(v),end(v)
#define clr(v) fill(all(v),0)
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define q_ceil(n,d) ((n - 1)/(d) + 1)
#define parity(a,b) ((a)^(b) & 1LL ^ 1LL)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;

const pair<int,int> DIR[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int INF_32 = -1 + (1 << 30);
const ll INF_64 = -1 + (1LL << 62);
const int MOD = (int)1e9 + 7;

ull next_subset(ull subset){
	ull tem = subset + (subset & -subset);
	ull btm = (~tem & subset) / (subset & -subset) >> 1;
	return btm | tem;
}

int N;
ll ans;
pair<int,int> p[200001];

void solve(){
	sort(p,p + N);
	int mx = 0,mn = INF_32,nn,nx;
	rep(i,N){
		mx = max(mx, p[i].sec);
		mn = min(mn, p[i].sec);
	}
	ans=1ll * (mx - mn) * (p[N - 1].fir - p[0].fir);
	nn = nx = p[0].fir;
    repD(i,N - 1,1){
        ans = min(ans,1ll * (p[N - 1].fir - mn)*(max(nx,p[i].fir)-min(nn,p[0].fir)));
        nn = min(nn,p[i].sec),nx = max(nx,p[i].sec); 
    }
	cout<<ans<<endl;
	
	return;
}

void input(){
	
	cin>>N;
	int x,y;
	rep(i,N){
		cin>>x>>y;
		if(x < y) swap(x,y);
		p[i] = {x,y};
	}
	
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	input();
	solve();
	
	return 0;
}



