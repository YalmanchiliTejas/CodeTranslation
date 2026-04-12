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
    vector<lint> v(n);
    repeat (i, n) cin >> v[i];
    
    lint ans = 0;
    repeat_from_to (i, 1, (n-1)/2) {
        lint tmp = 0;
        lint l = 0;
        lint r = n-1;
        do {
            tmp += v[l];
            tmp += v[r];
            ans = max(ans, tmp);
            l += i;
            r -= i;
            
            if ((n-1) % i == 0) {
                if (l >= r) break;
            }
            else {
                if (l >= (n-1)-i or r <= i) break;
            }
        } while (true);
    }
    cout << ans << endl;
}