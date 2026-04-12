#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    multiset<ll> st;
    for(ll i=0;i<n;i++){
         cin >> a[i];
         a[i]*=-1;
    }
    for(ll i=0;i<n;i++){
        auto itr = st.upper_bound(a[i]);
        if(st.end()!=itr){
            st.erase(itr);
            st.insert(a[i]);
        }
        else st.insert(a[i]);
    }
    cout << st.size() << endl;
    return 0;
} 