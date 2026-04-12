#include <bits/stdc++.h>
#define rep(n) for (int I = 0; (I) < (n); ++(I) )
#define repeat(i, n) for( int i = 0; (i) < (n); ++(i) )
#define repeat_to(i, n) for( int i = 0; (i) <= (n); ++(i) )
#define repeat_from(i, m, n) for( int i = (m); (i) < (n); ++(i) )
#define repeat_from_to(i, m, n) for( int i = (m); (i) <= (n); ++(i) )
#define dump(x) cout << " " << #x << "=" << x
#define vdump(v) for(size_t T=0; T<v.size(); ++T){cout << " " << #v << "[" << T << "]=" << v[T];} cout << endl
using namespace std;
using lint = long long;
using ld = long double;

int main(void) {
    int n;
    cin >> n;
    vector<string> ss(n);
    vector<vector<int>> appear(n, vector<int>(26, 0));
    
    auto c2i = [](const char c){return c - 'a';};
    auto i2c = [](const int i) {return (char)((int)'a' + i);};
    
    repeat(i, n) {
        cin >> ss[i];
        repeat(j, (int)ss[i].length()) {
            int idx = c2i(ss[i][j]);
            ++appear[i][idx];
        }
    }
    repeat(i, 26) {
        int mincnt = 1e5;
        repeat(j, n) {
            mincnt = min(mincnt, appear[j][i]);
        }
        char c = i2c(i);
        repeat(j, mincnt) {
            cout << c;
        }
    }
    cout << endl;
    return 0;
    
}