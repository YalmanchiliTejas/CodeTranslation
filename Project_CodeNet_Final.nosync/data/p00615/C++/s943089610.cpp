#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    while(true){
        cin>>n>>m;
        if(n==0&&m==0)break;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int t;
            cin>>t;
            v.emplace_back(t);
        }
        for (int i = 0; i < m; ++i) {
            int t;
            cin>>t;
            v.emplace_back(t);
        }
        v.emplace_back(0);
        sort(v.begin(),v.end());
        int ans=0;
        for (size_t i = 1; i < v.size(); ++i) {
            ans=max(ans,v[i]-v[i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
