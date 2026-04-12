#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
vector<int> v;
bool checked[5005][5005];
set<i_i> st;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        st.insert({v[i], i});
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(checked[i][j]) continue;
            checked[i][j] = true;
            int now = 2;
            int a = v[j];
            int LAST = j;
            while(true) {
                a += v[j] - v[i];
                auto itr = st.lower_bound({a, 0});
                if(itr != st.end() && (*itr).first == a) {
                    now++;
                    checked[LAST][(*itr).second] = true;
                    LAST = (*itr).second;
                } else break;
            }
            chmax(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}
