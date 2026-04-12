#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<61;
const double eps=1e-9;
const ll MOD=1e9+7;
int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    for(int i=1;i<=100;i++){
        bool f=true;
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=a[j];
            sum-=i;
            if(sum<0){
                f=false;
            }
        }
        if(f)ans=max(ans,i);
    }
    cout<<ans<<endl;
}

