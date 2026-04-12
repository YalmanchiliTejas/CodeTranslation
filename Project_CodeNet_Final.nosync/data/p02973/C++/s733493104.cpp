#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
const int MOD=1e9+7;
#ifndef HOME
#define cerr if(0)cerr
#endif

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    set<int>s;
    multiset<int>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    for(int i=0;i<n;i++){
        auto it=m.lower_bound(a[i]);
        if(it==m.begin()){
            m.insert(a[i]);
        }else{
            it--;
            m.erase(it);
            m.insert(a[i]);
        }
    }
    int count=m.size();
    cout<<count<<endl;
    
    return 0;
    
}

