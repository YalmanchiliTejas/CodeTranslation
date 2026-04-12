#include <bits/stdc++.h>

#define rep_(v, f, l) for (int v = (f), v##_ = (l); v < v##_; ++v)
#define rep(v, n) rep_(v, 0, n)
#define lep(v, n) rep_(v, 1, n + 1)
#define rrep_(v, f, l) for (int v = (l), v##_ = (f); v >= v##_; --v)
#define rrep(v, n) rrep_(v, 0, n - 1)
#define rlep(v, n) rrep_(v, 1, n)
#define show_a(a, size) rep(a##_it, size) std::cout << a[a##_it] << " \n"[a##_it == a##_it_ - 1];
#define show_v(v) show_a(v, v.size())
#define eachv(v, i) rep(i, v.size())
#define reachv(v, i) rrep(i, v.size())
#define debug(x) std::cerr << #x << " = " << x << "\n";

using namespace std;

typedef long long int lint;

static inline int in(){ int x; scanf("%d", &x); return x; }
static inline lint inl(){ lint x; scanf("%lld", &x); return x; }

int main()
{
    int a;
    while (a = in() + in()){
        vector<pair<int, char> > stores;
        stores.push_back(make_pair(a, 'A'));
        rep(i, 4){
            stores.push_back(make_pair(in() + in(), 'B' + i));
        }
        sort(stores.begin(), stores.end(), greater<pair<int, char> >());
        printf("%c %d\n", stores[0].second, stores[0].first);
    }
    return (0);
}