#include "bits/stdc++.h"
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
#define ALL(v) v.begin(), v.end()
#define FS first
#define SC second
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define SQR(x) ((x) * (x))
#define BIT(n) (1LL<<(n))
#define PCNT(x) __builtin_popcountll(x)
#define PB push_back
#define MP make_pair
#define endl "\n"
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<bool> VB;
typedef vector<vector<int> > VVI;
typedef vector<vector<bool> > VVB;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
const LL MOD=1000000007ll;
const LL INF=2000000000ll;
template <class T> bool chmax( T& a, T b );
template <class T> bool chmin( T& a, T b );
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

long power(long a,long b){return b?power(a*a%MOD,b/2)*(b%2?a:1)%MOD:1;}

long perm(int N, int K){
	long x=1;
	for(int i=1;i<=K;i++)
	{
		x=x*(N-i+1)%MOD;
	}
	return x%MOD;
}

long factorial(int N){
	return perm(N,N);
}

long comb(int N,int K){
	long x=1,y=1;
	for(int i=1;i<=K;i++)
	{
		x=x*(N-i+1)%MOD;
		y=y*i%MOD;
	}
	return x*power(y,MOD-2)%MOD;
}

long hcomb(int N, int K){
    return comb(N+K-1, N-1);
}

bool isprime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i ==  0) return false;
    }
    return true;
}

void eratosthenes(int n){
	// エラトステネスのふるい
    bitset<1000000> is_prime(0); // 十分大きなサイズを確保します
    for (int i = 2; i <= n; ++i) is_prime.set(i); // とりあえず全部ふるいに入れます
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) { // 素数 i を発見したら
            for (int j = i * 2; j <= n; j += i) {
                is_prime.reset(j); // i の倍数をふるい落とす
            }
        }
    }
	for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) cout << i << endl;
    }
}

void dfs(const vector<vector<int> > &G, int v, vector<int> &seen) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (int next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v, seen); // 再帰的に探索
    }
}

void bfs(const vector<vector<int> > &G, int v, vector<int> &dist){
    REP(i,SZ(dist)) dist[i] = -1; // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[v] = 0;
    que.push(v); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty()) {
        v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int next_v : G[v]) {
            if (dist[next_v] != -1) continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[next_v] = dist[v] + 1;
            que.push(next_v);
        }
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);

    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
}