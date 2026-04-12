#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>

using namespace std;

//#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ; //何もしない文
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#define pb push_back

typedef long long LL; 
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MAX_N = 10;

int N,M;
LL ans;
VI adj[MAX_N];

void bfs(int start, bool *visited)
{
    bool allVisited = true;

    for(int i = 0; i < N; i++)
    {
        if(visited[i] == false)  allVisited = false;
    }

    if(allVisited) 
    {
        ans++;
        return;
    }

    for(auto p : adj[start])
    {
        dump(start)
        dump(p)
        dump(visited[p])
        if(visited[p] == false)
        {
            visited[p] = true;
            bfs(p, visited);
            visited[p] = false;
        }
    }

    return;
}


int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    cin >> N >> M;
    REP(i,M)
    {
        int a,b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ans = 0;
    bool visited[MAX_N];
    REP(i,MAX_N)
    {
        visited[i] = false;
    }
    visited[0] = true;

    bfs(0,visited);
    cout << ans << endl;


}
