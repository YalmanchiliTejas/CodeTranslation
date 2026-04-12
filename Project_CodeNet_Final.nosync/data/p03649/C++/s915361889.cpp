#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const ll INF = 0x3fffffff;

ll solve(ll N, ll a){
	ll l=-1, r = 1e16;
	while(r-l>1){
		ll m = (l+r) / 2ll;
		if( a - m*(N-1) < N ){
			r = m;
		}else{
			l = m;
		}
	}
	cout << a << ":" << r << endl;
	return r;
}

int main(){
	//ios_base::sync_with_stdio(0);
	ll N, ans=0;
	ll a[305];

	cin >> N;
	rep(i,N) cin >> a[i];

	//priority_queue<ll, vector<ll>, greater<ll>> que;
	priority_queue<ll> que;
	rep(i,N) que.push( a[i] );
	ll line = N;
	while( que.top() >= line ){
		auto k = que.top();
		que.pop();
		ll m = (k - line + N) / N;
		//cout << "k=" << k << " m=" << m << endl;
		line -= m;
		que.push( k - m*(N+1) );
	}

	ans = N - line;
	cout << ans << endl;

	return 0;
}
