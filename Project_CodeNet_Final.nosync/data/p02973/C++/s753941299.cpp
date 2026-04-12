#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

typedef pair<int, int> P;
ll modnum = 1e9+7;



int main() {
    int n; cin >> n;
    deque<int> ans;
    rep(i, n) {
        int a; cin >> a;
        int itr = lower_bound(ans.begin(), ans.end(), a) - ans.begin();
        if(itr == 0) ans.push_front(a);
        else ans[itr-1] = a;
    }

//    rep(i, ans.size()) {
//        cout << ans[i] << endl;
//    }

    cout << ans.size() << endl;

    return 0;
}
