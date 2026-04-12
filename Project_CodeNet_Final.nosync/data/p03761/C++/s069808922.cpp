//header{{{
#include<bits/stdc++.h>
  
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define setout(n,x) setw(n+1) << setfill(x)
#define Fixed fixed << setprecision(10)
#define int int64_t
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod = 1e9+7; 

template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }

template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
  
int gcd(int a,int b){ return b ? gcd(b,a % b) : a;}
int lcm(int a,int b){ return a / gcd(a,b) * b;}
//}}}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int> > cnt(n,vector<int>(26));
	string s;
	rep(i,n){
		cin >> s;
		rep(j,s.size()){
			++cnt[i][s[j]-'a'];
		}
	}
	rep(i,26){
		int minv = INF;
		rep(j,n){
			chmin(minv,cnt[j][i]);
		}
		rep(j,minv){
			cout << char('a' + i);
		}
	}
	cout << '\n';
	return 0;
}
