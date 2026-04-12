#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(void){
    int n; cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    multiset <int> se;
    se.insert(-114514);
    se.insert(a[0]);
    for(int i=1;i<n;i++){
        auto x = (--se.lower_bound(a[i]));
        if(*x== -114514) se.insert(a[i]);
        else{
            se.erase(x);
            se.insert(a[i]);
        }
    }
    cout<<se.size()-1<<endl;
}
