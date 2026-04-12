#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
const ll INF = 1LL << 60;
const int mod = 1e9+7;
//Write From this Line
vector<int> G[10] ;
int main()
{
	int n , m ;
	cin >> n >> m ;
	rep(i,m){
		int a , b;
		cin >> a >> b;
		--a; --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int B[n-1];
	rep(i,n-1) B[i] = i+1;
	ll ans = 0 ;
	do {
		bool can = true; 
		//頂点0から初めて0 -> B[0] -> B[1] -> .. -> B[n-2] と行けるか.
		int count = 1 ;//通った頂点の数
		int from = 0 ;
		int to ;
		while(count < n){
			to = B[count-1];
			//G[from]の中にtoがあればok
			for(int i = 0 ; i < G[from].size() ; i ++){
				if ( G[from][i] == to) {
					//ok
					count ++ ;
					from = to;
					break ;
				} 
			}
			if( to != from ){
				break ;
			}
		}
		if( count == n ){
			ans ++ ;
		}
	} while(next_permutation(B,B+n-1));
	cout << ans << endl;
}
