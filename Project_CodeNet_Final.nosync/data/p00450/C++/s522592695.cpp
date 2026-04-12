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
int in(){int a;scanf("%d",&a);return a;}
ll lin(){ll a;scanf("%lld",&a);return a;}

constexpr int inf = 1e9;
constexpr ll linf = 3e18;
constexpr double eps = 1e-9;

struct data {
    int sz, c;
    data(int sz, int c) : sz(sz), c(c) {}
};

int c[100010];

int main()
{
    int n;

    while (n = in(), n) {
        rep(i, n) {
            c[i] = in();
        }

        vector<data> hoge;

        hoge.PB(data(1, c[0]));

        for (int i = 1; i < n; ++i) {
            if (i % 2 == 0) {
                if (hoge.back().c == c[i]) {
                    hoge.back().sz += 1;
                } else {
                    hoge.PB(data(1, c[i]));
                }
            } else {
                if (hoge.back().c == c[i]) {
                    hoge.back().sz += 1;
                } else {
                    int a = hoge.back().sz;
                    hoge.pop_back();
                    if (hoge.empty()) hoge.PB(data(a + 1, c[i]));
                    else hoge.back().sz += a + 1;
                }
            }
        }

        int ans = 0;

        while (hoge.size()) {
            if (hoge.back().c == 0) ans += hoge.back().sz;
            hoge.pop_back();
        }

        printf("%d\n", ans);
    }
}