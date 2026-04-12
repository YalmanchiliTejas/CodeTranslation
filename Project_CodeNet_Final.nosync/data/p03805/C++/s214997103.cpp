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
constexpr int MOD = 998244353;

template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }

template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class A, class B> using umap = unordered_map<A,B>;
  
int gcd(int a,int b){ return b ? gcd(b,a % b) : a;}
int lcm(int a,int b){ return a / gcd(a,b) * b;}

constexpr int dx[] = {1,0,-1,0,1,1,-1,-1};
constexpr int dy[] = {0,-1,0,1,1,-1,-1,1};
//}}}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;
    vector<int> route(n-1);
    vector<vector<bool> > graph(n+1,vector<bool>(n+1));

    for(int i = 2;i <= n;++i) route[i-2] = i;

    rep(i,m){
        int a,b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }

    int res = 0;

    do{
        rep(i,n-2){
            if(i == 0){
                if(!graph[1][route[i]]) goto ng;
            }
            if(!graph[route[i]][route[i+1]]) goto ng;
        }
        ++res;
        ng:;
    }while(next_permutation(all(route)));

    cout << res << '\n';

  	return 0;
}
