#include <bits/stdc++.h>
#ifdef _WIN32
#include "debug.hpp"
#endif
using namespace std;

#define rep(i,N) repf(i,0,N)
#define reps(i,N) repfs(i,1,N)
#define repf(i,a,b) for(int i=a;i<b;i++)
#define repfs(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,N) for(int i=N-1;i>=0;i--)
#define reprs(i,N) for(int i=N;i>0;i--)
#define pb push_back
#define pob pop_back

template<typename T> 
void chmax(T &a,T b){ a = max(a, b);};
template<typename T> 
void chmin(T &a,T b){ a = min(a, b);};

typedef long long ll;
typedef pair<int,int> P;
const int INF = 100000000;
const int MOD = 1000000007;
const int dx[9] = { 0, 1,  0, -1, 1,  1, -1, -1, 0};
const int dy[9] = { 1, 0, -1,  0, 1, -1, -1,  1, 0};
//--------------------------------------//
int n;
ll x;
ll s[51];
ll p[51];

ll f(int n, ll x){
	if (x <= 1) return 0;
	else if(x < 1 + s[n-1]) return f(n-1, x-1);
	else if(x == 1 + s[n-1]) return p[n-1];
	else if (x== 2 + s[n-1]) return p[n-1] + 1;
	else if (x < 2 + s[n-1] * 2) return p[n-1] + 1 + f(n-1, x-(2+s[n-1]));
	else return p[n-1] * 2 +1;
}

void solve(){
	s[0]=1;
	p[0]=1;
	rep(i,n){
		s[i+1] = s[i]*2 + 3;
		p[i+1] = p[i]*2 + 1;
	}
	ll ans= f(n,x);
	cout<<ans<<endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>x;
	solve();
	return 0;
}
