#include <bits/stdc++.h>
#define rep(n) for(lint I = 0; (I) < (lint)(n); ++(I))
#define repeat(i, n) for(lint i = 0; (i) < (lint)(n); ++(i))
#define repeat_to(i, n) for(lint i = 0; (i) <= (lint)(n); ++(i))
#define repeat_from(i, m, n) for(lint i = (m); (i) < (lint)(n); ++(i))
#define repeat_from_to(i, m, n) for(lint i = (m); (i) <= (lint)(n); ++(i))
#define el cout<<endl
#define dump(x) cout<<" "<<#x<<"="<<x
#define vdump(v) for(size_t I=0; I<v.size(); ++I){cout<<" "<<#v<<"["<<I<<"]="<<v[I];} cout<<endl
using namespace std;
using lint = long long;
using ld = long double;

int main(void) {
    lint n; cin >> n;
    vector<lint> a(n); repeat(i, n) cin >> a[i];
    
    lint s = accumulate(a.begin(), a.end(), 0LL);
    
    repeat_from_to(k, s - n * (n - 1), s) {
        if (k < 0) continue;
        lint z = 0;
        repeat(i, n) {
            lint b = (a[i] + k) % (n + 1);
            if (b == n) goto LABEL;
            z += b;
        }
        if (z == s - k) {
            cout << k << endl;
            break;
        }
    LABEL:;
    }
    return 0;
}