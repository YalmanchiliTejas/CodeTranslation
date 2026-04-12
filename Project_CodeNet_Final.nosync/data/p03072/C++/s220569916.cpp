#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin>>a[i];
    int m = a[0], c = 1;
    for (int i=1; i<n; ++i){
        if (a[i]>= m) ++c;
        m = max(m, a[i]);
    }
    cout<<c;
    return 0;
}
