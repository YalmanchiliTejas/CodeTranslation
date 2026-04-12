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


int main(){
	//ios_base::sync_with_stdio(0);
	ll N;
	int a[200005];

	cin >> N;
	rep(i,N) cin >> a[i];

	vector<int> ans;
	rep(i,(N+1)/2) ans.push_back( a[i*2] );
	reverse( all(ans) );
	rep(i,(N+0)/2) ans.push_back( a[i*2+1] );
	if( N%2 == 0 ) reverse( all(ans) );

	for(auto t: ans)
		cout << t << " ";
	cout << endl;

	return 0;
}