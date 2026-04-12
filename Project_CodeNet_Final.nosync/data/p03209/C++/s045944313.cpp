#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define MOD 1000000007
#define ll long long
using namespace std;
typedef unsigned long long ull;
typedef pair<ll,ll> pr;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<pr>v(51);
    // p,b
    v[0]=make_pair(1,0);
    for(int i=0;i<50;i++){
        ll p=2*v[i].first+1;
        ll b=2*v[i].second+2;
        v[i+1]=make_pair(p,b);
//        cout<<p<<" "<<b<<endl;
    }
    vector<ll> s(51);
    s[0]=1;
    ll x=1;
    for(int i=0;i<51;i++){
        s[i]=x;
        x=x*2+3;
    //    cout<<s[i]<<endl;
    }
    ll n,eat;
    cin>>n>>eat;
    ll ans=0;
    // B BPPPB P BPPPB B
    for(int i=n-1;i>=0;i--){
        if(eat==1){
            break;
        }
        else if(eat<1+s[i]){
            eat-=1LL;
        }
        else if(eat==1+s[i]){
            ans+=v[i].first;
            break;
        }
        else if (eat==2+s[i]){
        //    cout<<"vv"<<v[i].first<<endl;
            ans+=v[i].first+1LL;
            break;
        }
        else if(eat<2+2*s[i]){
            ans+=v[i].first+1;
            eat-=(2LL+s[i]);
        }
        else{
            ans+=2LL*v[i].first+1LL;
            break;
        }
//        cout<<ans<<" "<<eat<<endl;
    }
    cout<<ans<<endl;
    return 0;
}