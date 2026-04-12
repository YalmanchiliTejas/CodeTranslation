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

const ll INF = 1e9+7;


int main(){
	ios_base::sync_with_stdio(false);
	int N, ans=0;
	int X[200005];
	vector<int> v;

	cin >> N;
	rep(i,N){
		cin >> X[i];
		v.push_back( X[i] );
	}

	sort( all(v) );

	rep(i,N){
		if( X[i] <= v[N/2-1] ) cout << v[N/2] << endl;
		else cout << v[N/2-1] << endl;
	}

	return 0;
}