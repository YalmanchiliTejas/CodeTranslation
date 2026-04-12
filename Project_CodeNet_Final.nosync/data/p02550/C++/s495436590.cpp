#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,X,M;
int main(){
    cin>>N>>X>>M;
    map<ll,ll> mp;
    for(ll i=0;i<M;i++)mp[i]=-1;
    vector<ll> v;
    while(v.size()<N){
        if(mp[X]!=-1){
            ll ans=0;
            for(ll i=0;i<mp[X];i++){
                ans+=v[i];
            }
            ll sum=0;
            for(ll i=mp[X];i<v.size();i++){
                sum+=v[i];
            }
            ans+=(N-mp[X])/(v.size()-mp[X])*sum;
            for(ll i=mp[X];i<mp[X]+(N-mp[X])%(v.size()-mp[X]);i++){
                ans+=v[i];
            }
            cout<<ans<<endl;
            return 0;
        }
        mp[X]=v.size();
        v.push_back(X);
        X=(X*X)%M;
    }

    ll ans=0;
    for(auto x:v) ans+=x;
    cout<<ans<<endl;

    return 0;
}