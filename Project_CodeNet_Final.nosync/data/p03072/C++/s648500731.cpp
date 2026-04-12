#include <bits/stdc++.h>
#define fst first
#define snd second
#define rep(n) for(lint I = 0; (I) < (lint)(n); ++(I))
#define repeat(i, n) for(lint i = 0; (i) < (lint)(n); ++(i))
#define repeat_to(i, n) for(lint i = 0; (i) <= (lint)(n); ++(i))
#define repeat_from(i, m, n) for(lint i = (m); (i) < (lint)(n); ++(i))
#define repeat_from_to(i, m, n) for(lint i = (m); (i) <= (lint)(n); ++(i))
#define repeat_reverse_from_to(i, m, n) for(lint i = (m); (i) >= (lint)(n); --(i))
#define el cout<<endl
#define es cout<<" "
#define dump(x) cout<<" "<<#x<<"="<<x
#define pdump(p) cout<<" "<<#p<<"=("<<p.fst<<","<<p.snd<<")"
#define vdump(v) for(size_t I=0; I<v.size(); ++I){cout<<" "<<#v<<"["<<I<<"]="<<v[I];} cout<<endl
using namespace std; using lint = long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<lint, lint>;
template<class T> vector<T> make_vec(size_t a){return vector<T>(a);}
template<class T, class... Ts> 
auto make_vec(size_t a, Ts... ts){return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));}

int main(void) {
    int n; cin >> n;
    vector<int> h(n);
    repeat (i, n) cin >> h[i];
    
    int mh = 0;
    int cnt = 0;
    repeat (i, n) {
        if (h[i] >= mh) ++cnt;
        mh = max(h[i], mh);
    }
    cout << cnt << endl;
}