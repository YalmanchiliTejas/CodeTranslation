#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
 
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    multiset<int> st;
    st.insert(a[0]);
    st.insert(-3);
    for(int i=1;i<n;i++){
        
        auto itr = st.lower_bound(a[i]);
        itr--;
        if(*itr<0 ||  *itr >= a[i]){
            //cerr<<*itr<<" "<<a[i]<<endl;
            st.insert(a[i]);
        }
        else {
            st.erase(itr);
           
            st.insert(a[i]);
        }
    }
    cout<<st.size()-1<<endl;
    
    
}