#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    multiset<ll> st;
    ll a;
    REP(i,n){
        cin >> a;
        auto itr = st.lower_bound(a);
        if(itr == st.begin()) st.insert(a);
        else{
            itr--;
            st.erase(itr);
            st.insert(a);
        }
    }
    cout << st.size() << endl;
    return 0;
}