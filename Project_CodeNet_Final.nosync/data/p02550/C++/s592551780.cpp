#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n,x,m,newone;
    cin>>n>>x>>m;
    vector<long long>a;
    a.push_back(x);
    set<long long>st;
    st.insert(x);
    for(int i=1;i<=n;i++) {
        newone = (a[i-1]*a[i-1])%m;
        if(st.find(newone)!=st.end()) break;
        st.insert(newone);
        a.push_back(newone);
    }
    long long ans=0;
    long long sum=0;
    int ind=0;
    int sz=a.size();
    // for(int i=0;i<sz;i++) cout<<a[i]<<" ";
    // cout<<endl;
    // cout<<sz<<endl;
    if(n<=sz) {
        for(int i=0;i<n;i++) ans+=a[i];
    }
    else {
        for(int i=0;i<sz;i++) {
            if(a[i]==newone) {
                ind=i;
                break;
            }
            ans+=a[i];
        }
        for(int i=ind;i<sz;i++) sum+=a[i];
        ans+= (sum*((n-ind)/(sz-ind)));
        for(int i=ind;i<ind+(n-ind)%(sz-ind);i++) ans+=a[i];
    }
   
    cout<<ans<<endl;

    return 0;
}