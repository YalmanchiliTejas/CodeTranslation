#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 1ll<<59

int main(){
    ll i,j;
    ll n;
    cin>>n;
    vector<ll> v;
    for(i=0;i<n;i++){
        ll x;
        cin>>x;
        x=-x;
        auto it=upper_bound(v.begin(),v.end(),x);
        if(it==v.end()) v.pb(x);
        else v[it-v.begin()]=x;       
    }
    cout<<v.size()<<endl;
    
}