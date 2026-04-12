#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

vector<int> anschar('z'+1, INT_MAX);

void update(vector<int> &v){
    reps(i,'a','z'){
        anschar[i] = min(anschar[i], v[i]);
    }
}

signed main() {
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        vector<int> v('z'+1, 0);
        for(char c : s){
            v[c]++;
        }
        update(v);
    }
    
    reps(i,'a','z'){
        rep(_,anschar[i]) cout << (char) i;
    }
    cout << endl;
}