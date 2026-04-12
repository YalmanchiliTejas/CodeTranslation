#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ii=pair<ll,ll>;
using vi=vector<ll>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (ll)1e18
#define all(x) (x).begin(),(x).end()
#define print(a); for(auto x:a)cout<<x<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;cin>>n;
    map<ll,ll,greater<ll>>v;
    ll a;ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(v.empty()){v[a]++;sum++;continue;}
        auto y=(*v.rbegin()).fi;
        if(a<=y){v[a]++;sum++;continue;}
        ll ans=-1;
        for(auto x:v){if(x.fi<a){ans=x.fi;break;}}
        if(v[ans]==1)v.erase(ans);
        else v[ans]--;
        v[a]++;
    }
    cout<<sum<<"\n";
}
