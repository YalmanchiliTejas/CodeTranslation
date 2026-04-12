#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
ll arr[100005];

map <ll,ll> bit;

ll compute(ll idx){
    ll ans = 0;
    while(idx>=0){
        ans = max(ans,bit[idx]);
        idx = (idx&(idx+1))-1;
    }
    return ans;
}

void update(ll idx,ll delta){

    while(idx<n){

        bit[idx] = max(bit[idx],delta);
        idx = (idx|(idx+1));
    }

}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }

    map <ll,ll> mp;
    ll ans = 0;
    set < pair <ll,ll> > s;
    for(ll i=0;i<n;i++){

        auto x = s.lower_bound({arr[i],0});
        if(x==s.begin()){
            s.insert({arr[i],++ans});
        }
        else{
            x--;
            ll c = x->second;
            s.erase(x);
            s.insert({arr[i],c});
        }

    }
    cout<<ans<<endl;






}
