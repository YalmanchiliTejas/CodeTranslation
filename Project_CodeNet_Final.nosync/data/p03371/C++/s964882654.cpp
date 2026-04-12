#include <bits/stdc++.h>

//{ SFT
using namespace std;
#define int int64_t
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define reps(i, a, n) for (int i = (a); i > (n); --i)
#define arep(i, x) for (auto &&i : (x))
#define irep(i, x) for (auto i = (x).begin(); i != (x).end(); ++i)
//降順はgreater<T>()
#define all(x) (x).begin(), (x).end()
#define rv(s) reverse((s).begin(), (s).end())
//gcd lcmはそのままok
#define gcd(a, b) __gcd(a, b)
#define bit(n) (1LL << (n))
#define bits(n) bitset(n)
#define pcnt(x) __builitin_popcountll(x)
//配列内等要素削除
#define unique(x) (x).erase(unique(x).begin(),(x).end()),(x).end());
#define Fixed(n) fixed << setprecision(n)
//総和
#define sowa(n) ((n) * ((n) + 1)) / 2
#define pb(x, a) (x).push_back(a)
#define fb(x, a) (x).flont_back(a)
#define eb(x, a) (x).emplaes_back(a)
#define F first
#define S second
#define cauto (const auto &)
template <class A, class B>
using pii = vector<pair<A, B>>;
template <class T> //昇順
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T> //降順
using max_heap = priority_queue<T>;
template <class A, class B>
using umap = unordered_map<A, B>;
template <class A>
using uset = unordered_set<A>;
template <class T>
bool chmax(T &a, const T &b) //最大値更新 返り値はbool
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) //最小値更新 返り値はbool
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr long long mod1 = 1e9 + 7;
constexpr long long mod2 = 998244353;
//} END

signed main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a,b,ab,x,y,cnt,ans=INF;
    int zo = 0;
    cin>>a>>b>>ab>>x>>y;

    for(int i=0; i<=1e5; ++i){
        cnt = i * 2*ab + max(zo,x-i)*a + max(zo,y-i) * b;
        chmin(ans,cnt);
    }

    cout<<ans<<'\n';
    return 0;
}