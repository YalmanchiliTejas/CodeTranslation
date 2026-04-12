#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=100000000000000LL;
const int MAX=100001;
const double EPS=1e-10;
int main() {
    ll n;
    cin>>n;
    ll a[51];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    while(1){
        ll sum=0;
        bool f=true;
        for(int i=0;i<n;i++){
            sum+=a[i]/n;
            if(a[i]>=n){
                f=false;
            }
        }
        if(f){
            break;
        }
        for(int i=0;i<n;i++){
            ll m=a[i]/n;
            a[i]-=m*n;
            a[i]+=sum-m;
            ans+=m;
        }
    }
    cout<<ans<<endl;
}
