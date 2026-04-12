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
	//ios_base::sync_with_stdio(false);
	int A, B;
	int d[20][20];

	cin >> A >> B;
	rep(i,A) rep(j,B) cin >> d[i][j];

	vector<pair<pii,int>> v;
	bool ok[20][20] = {};
	rep(a,101) rep(b,101) rrep(c,101){
		bool f = true, check = false;
		rep(i,A) rep(j,B){
			int s = a*(i+1) + b*(j+1) + c;
			if( d[i][j] > s ) f = false;
		}
		if(!f) break;
		rep(i,A) rep(j,B){
			int s = a*(i+1) + b*(j+1) + c;
			if( f && d[i][j] == s ){
				ok[i][j] = true;
				check = true;
			}
		}
		if(f && check) v.emplace_back(pii(a,b), c);
	}

	bool ans = true;
	rep(i,A) rep(j,B) if( !ok[i][j] ) ans = false;

	if( !ans ){
		cout << "Impossible" << endl;
		return 0;
	}else{
		cout << "Possible" << endl;
	}

	vector<pair<pii,int>> edge;
	rep(i,101) edge.emplace_back( pii(i+1,i+2), -1 );
	rep(i,101) edge.emplace_back( pii(200+i-1,200+i), -2 );
	for(auto p: v){
		int a = p.X.X;
		int b = p.X.Y;
		int c = p.Y;
		edge.emplace_back( pii(a+1, 300-b), c );
	}

	cout << 300 << " " << edge.size() << endl;
	for(auto t: edge){
		cout << t.X.X << " " << t.X.Y << " ";
		if( t.Y == -1 ) cout << "X" << endl;
		else if( t.Y == -2 ) cout << "Y" << endl;
		else cout << t.Y << endl;
	}
	cout << 1 << " " << 300 << endl;

	return 0;
}
