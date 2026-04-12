#include <bits/stdc++.h>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> lpair;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define rREP(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int ary[n];
    rep(i, n) cin >> ary[i];

    multiset<int> st;
    st.insert(ary[0]);
    REP(i, 1, n) {
        auto iter = st.lower_bound(ary[i]);
        // iter --;
        // int value = *iter;
        if (iter == st.begin() ) {
            st.insert(ary[i]);
        }
        else
        {
            iter --;
            st.erase(iter);
            st.insert(ary[i]);
            /* code */
        }
    }


    cout << st.size() << endl;
}
