#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    multiset<ll> st;
    for(ll i=0;i<n;i++) cin >> a[i];
    for(ll i=0;i<n;i++){
        auto itr = st.lower_bound(a[i]);
        if(st.begin()!=itr){
            itr--;
            st.erase(itr);
            st.insert(a[i]);
        }
        else st.insert(a[i]);
    }
    cout << st.size() << endl;
    return 0;
} 