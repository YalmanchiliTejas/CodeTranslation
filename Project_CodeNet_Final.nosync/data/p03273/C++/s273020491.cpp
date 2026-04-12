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
#define dump(x) cout<<" "<<#x<<"="<<x
#define vdump(v) for(size_t I=0; I<v.size(); ++I){cout<<" "<<#v<<"["<<I<<"]="<<v[I];} cout<<endl
using namespace std;
using lint = long long;
using ld = long double;

int main(void) {
    int h, w;
    cin >> h >> w;
    vector<string> ss;
    rep (h) {
        string s;
        cin >> s;
        string blank_row(w, '.');
        if (s == blank_row) {
            continue;
        }
        ss.push_back(s);
    }
    
    h = ss.size();
    vector<bool> v(w, true);
    repeat (i, w) {
        repeat (j, h) {
            if (ss[j][i] != '.') {
                v[i] = false;
                break;
            }
        }
    }
    
    repeat (j, h) {
        repeat (i, w) {
            if (v[i]) continue;
            cout << ss[j][i];
        }
        cout << endl;
    }
}