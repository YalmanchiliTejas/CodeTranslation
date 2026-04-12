#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
int main() {
    int n;
    cin>>n;
    int a[n];
    rep(i,n){
        cin>>a[i];
    }
    multiset<int> ms;
    ms.insert(a[0]);
    rep(i,n-1){
        auto index=ms.lower_bound(a[i+1]);
        if (index!=ms.begin()){
            ms.erase(--index);
        }
        ms.insert(a[i+1]);

    }
    cout<<ms.size()<<endl;

    

    return 0;
}
