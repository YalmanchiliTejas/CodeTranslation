#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_v(size_t a, Ts... ts) {return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }

template<typename T,typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v){ t = v; }

template<typename T,typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v){ for(auto &e : t) fill_v(e, v); }

const int INF = (int)1e9;
const LL INFL = (LL)1e18;
const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n)
    {
        cin >> a[i];
    }
    
    multiset<int> que;
    que.insert(a[0]);
    FOR(i, 1, n)
    {
        auto itr = que.lower_bound(a[i]);
        if(itr == que.begin())
        {
            que.insert(a[i]);
        }
        else
        {
            itr--;
            que.erase(itr);
            que.insert(a[i]);
        }
    }
    cout << que.size() << endl;
}