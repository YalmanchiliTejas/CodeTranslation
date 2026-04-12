#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl


int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    multiset<ll> st;
    st.insert(-1);
    st.insert(1e9+7);
    for(int i = 0; i < n; i++){
        auto itr = st.lower_bound(a[i]);
        itr--;
        if((*itr)==-1){
            st.insert(a[i]);
        }else{
            st.erase(itr);
            st.insert(a[i]);
        }
    }

    cout << st.size()-2 << endl;
    return 0;

}
