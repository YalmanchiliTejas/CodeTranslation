/*+lmake
 * STD = c++14
 * DEFINE += WAAUTOMATON
 */
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#ifdef WAAUTOMATON
#define debug(args...)                                                                             \
    {                                                                                              \
        dbg, args;                                                                                 \
        cerr << endl;                                                                              \
    }
#define massert(x) assert(x)
#else
#define debug(args...) // Just strip off all debug tokens
#define massert(x)
#endif
struct debugger
{
    template <typename T>
    debugger &operator,(const T &v)
    {
        cerr << v << " ";
        return *this;
    }
} dbg;
const int MAXN = 100000;
vector<int> g[MAXN + 10];
int in[MAXN + 10];
bool vis[MAXN + 10];
int cnt[MAXN + 10];
int dfs(int now,int fa)
{
	int cnt=0;
	for(auto i:g[now]) {
		if (i!=fa) {
			cnt+=dfs(i,now);
		}
	}
	if (cnt>1)
		throw 1;
	return cnt^1;
}
void solve(long long n, vector<long long> a, vector<long long> b)
{
    int sum = n;
    for (int i = 0; i < n - 1; ++i) {
        g[a[i]].push_back(int(b[i]));
        g[b[i]].push_back(a[i]);
        in[a[i]]++;
        in[b[i]]++;
    }
	bool flag=true;
	try {
		int x= dfs(1,0);
		if (x==1) flag=false;
	} catch(...) {
		flag=false;
	}
	if (flag) {
		puts("Second");
	} else {
		puts("First");
	}
}

int main()
{
#ifdef WAAUTOMATON
    freopen("./in_D_2.txt","r",stdin);
#endif
    long long N;
    scanf("%lld", &N);
    vector<long long> a((N - 1) - 1 + 1);
    vector<long long> b((N - 1) - 1 + 1);
    for (int i = 0; i <= (N - 1) - 1; i++) {
        scanf("%lld", &a[i]);
        scanf("%lld", &b[i]);
    }
    solve(N, a, b);
    return 0;
}
