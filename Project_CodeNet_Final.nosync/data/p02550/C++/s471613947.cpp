#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <stack>
#include <queue>
#include <deque>
#include <functional>

using namespace std;

#define fst first
#define scd second
#define PB push_back
#define MP make_pair
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define omajinai ios::sync_with_stdio(false);cin.tie(0)
#define rep(i,x) for(int i=0;i<(int)(x);++i)
#define rep1(i,x) for(int i=1;i<=(int)(x);++i)
#define rrep(i,x) for(int i=(int)x-1;i>=0;--i)
#define rrep1(i,x) for(int i=(int)x;i>=1;--i)

using ll=long long;
using ld=long double;
using vi=vector<int>;
using vvi=vector<vi>;
using pii=pair<int, int>;
using vpii=vector<pii>;

template<class T,class U>ostream&operator<<(ostream&os,const pair<T,U>p){os<<"("<<p.fst<<", "<<p.scd<<")";return os;}
template<class T>ostream&operator<<(ostream&os,const vector<T>v){rep(i,v.size()){if(i)os<<", ";os<<v[i];}return os;}
template<typename T>T&max(T&a,T&b){if(a>=b)return a;return b;}
template<typename T>T&min(T&a,T&b){if(a < b)return a;return b;}
template<typename T>bool chmax(T&a,T b){if(a < b){a=b;return true;}return false;}
template<typename T>bool chmin(T&a,T b){if(a > b){a=b;return true;}return false;}
constexpr ll TEN(ll n){return n==0?1:10ll*TEN(n-1);}

constexpr ll inf = TEN(9)+5;
constexpr ll linf = 3*TEN(18);

#define int long long

ll N;
int X, M;

int idx[100010];

signed main()
{
    cin >> N >> X >> M;

    vector<int> S, hoge;
    S.emplace_back(X);

    memset(idx, -1, sizeof idx);
    idx[X] = 0;
    int len = 1;

    int til_idx = -1;

    ll sum1 = 0, sum2 = 0;
    int seq_len = -1;

    bool too_long = false;

    for (int i = 0; i < N - 1; ++i) {
        int nxt = (ll)S[i] * S[i] % M;
        //printf("S[%d] = %d\n", i+1,nxt);
        //printf("idx[%d] = %d\n", nxt, idx[nxt]);
        if (idx[nxt] != -1) {
            //printf("idx[nxt] = %d\n", idx[nxt]);
            too_long = true;
            til_idx = idx[nxt];
            for (int j = 0; j < til_idx; ++j) sum1 += S[j];
            for (int j = til_idx; j <= S.size() - 1; ++j) {
                sum2 += S[j];
                hoge.emplace_back(S[j]);
            }
            N -= S.size();
            seq_len = i - til_idx + 1;
            break;
        }
        S.emplace_back(nxt);
        idx[nxt] = i + 1;
        len++;
    }

    if (not too_long) {
        cout << accumulate(all(S), 0ll) << endl;
    } else {
        ll ans = sum1 + sum2;

        ans += (ll)N / seq_len * sum2;

        N %= seq_len;

        rep(i, N) ans += hoge[i];

        cout << ans << endl;
    }
}
