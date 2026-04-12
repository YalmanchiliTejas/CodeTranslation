#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
#define all(n) begin(n), end(n)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int main()
{
ios::sync_with_stdio(false);cin.tie(0);
    ll N,X,M;
    cin>>N>>X>>M;
    vint loop;
    vector<int> seen(M+1,-1);
    int beforeLoop = 0; //ループが始まるまでの長さ
    ll now = X; //最初
    while(seen[now] == -1)
    {
        seen[now] = 0;
        now = (now*now)%M;
        beforeLoop++;
    } 
    ll loopStart = now; //ループが始まる場所
    int loopLength = 0; //ループの長さ(周期)
    do
    {
        seen[now] = loopLength+1;
        now = (now*now)%M;
        loopLength++;
    } while (now != loopStart);
    ll ans = 0;
    ll rem = (N-beforeLoop+loopLength) % loopLength;
    ll div = (N-beforeLoop+loopLength) / loopLength;
    for (size_t i = 0; i <= M; i++)
    {
        if(seen[i]==-1)
        continue;

        if(seen[i]==0)
        {
            ans += i;
        }
        else{
            ans += div*i;
            if(seen[i] <= rem)
            ans += i;
        }
    }
    cout<<ans;
    return 0;
}