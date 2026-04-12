#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static const long long INF=1e9+5;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    reverse(a.begin(),a.end());
    vector<long long> dp(n,INF);

    for(int i=0;i<n;++i) *upper_bound(dp.begin(),dp.end(),a[i])=a[i];
    int res=lower_bound(dp.begin(),dp.end(),INF)-dp.begin();

    cout<<res<<endl;
}