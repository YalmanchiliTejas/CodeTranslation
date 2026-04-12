// aftershock :D
#include "bits/stdc++.h"
#include "sstream"
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const int N=3e5+1;
multiset<int> st;
int main() {
    quick
    int n, x; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
    auto it = st.lower_bound(x);
    if (it == st.begin())
        st.insert(x);
    else
        it--, st.erase(it), st.insert(x);}
    cout<<st.size();
}