#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    vector<int>vv=v;
    sort(v.begin(),v.end());
    int ans1=v[n/2],ans2=v[n/2-1];
    for(int i=0;i<n;++i){
        if(vv[i]<=ans2)cout<<ans1<<endl;
        else cout<<ans2<<endl;
    }
    return 0;
}