#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    multiset<int> st;
    int t;
    int ans=0;
    for (int i = 0; i < n; ++i) {
        cin>>t;
        auto it=st.lower_bound(t);
        if(it==st.begin()){
            st.insert(t);
            ++ans;
        }
        else{
            --it;
            st.erase(it);
            st.insert(t);
        }
    }
    cout<<ans<<endl;
    return 0;
}