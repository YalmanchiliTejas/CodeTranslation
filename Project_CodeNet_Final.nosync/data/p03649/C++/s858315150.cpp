#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool flag=true;
    ll ans=0;
    int cnt=0;
    while(flag){
        flag=false;
        for(int i=0;i<n;i++){
            if(a[i]<n)continue;
            ll t=a[i]/n;
            flag=true;
            ans+=t;
            for(int j=0;j<n;j++){
                if(i!=j){
                    a[j]+=t;
                }
            }
            a[i]%=n;
        }
    }
    cout<<ans<<endl;
}
