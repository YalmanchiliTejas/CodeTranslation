#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
int nums[200001];
int psa[200002];
int m=(int)(1e9+7);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll allsum=0, ans=0;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>nums[i];
        if(i!=0) allsum+=nums[i];
    }
    for(int i=0;i<n-1;++i){
        ans=ans+(((nums[i]%m) * (allsum%m)) %m);
        allsum-=nums[i+1];
    }
    cout<<ans%m<<endl;

}