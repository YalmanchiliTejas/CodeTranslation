#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
    int n;
    cin>>n;
    vector<int> x,a;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        x.push_back(j);
        a.push_back(j);
    }
    sort(a.begin(),a.end());
    int ans1,ans2;
    ans1=a[n/2-1];
    ans2=a[n/2];
    for(int i=0;i<n;i++){
        if(x[i]<=ans1) cout<<ans2<<endl;
        else cout<<ans1<<endl;
    }
    return 0;
}
