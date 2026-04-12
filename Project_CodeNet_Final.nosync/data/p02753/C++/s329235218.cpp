#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define gcd __gcd
bool compare(ll x, ll y){
    return x>y;
}
ll isprime(ll n){
    if(n==1) return 0;
    else if(n==2) return 1;
    else{
        for(ll i=2;i<=sqrt(n);i++){
            if(n%i==0) return 0;
        }
    return 1;   
    }
}
vector<ll> get_prime_less(ll n){
    ll array[n];
    vector<ll> factor;
    for(ll i=1;i<=n;i++) array[i]=i;
    ll prime[n];
    for(ll i=0;i<n;i++) prime[i]=1;
    for(ll i=2;i<=sqrt(n);i++){
        if(prime[i]==1){
            for(ll j=i*i;j<=n;j=j+i) prime[j]=0; 
            factor.push_back(i);
        }
    }
    return factor;
}
vector<ll> retain_index(ll arr[], ll n){ 
    vector<pair<ll, ll> > vp; 
    for (ll i = 0; i < n; ++i) { 
        vp.push_back(make_pair(arr[i], i)); 
    } 
    sort(vp.begin(), vp.end());
    vector<ll> retain;
    for (ll i = 0; i < vp.size(); i++) { 
        ll a = vp[i].second;
        retain.pb(a);
    }
    return retain;
}
int main(){
    string s;
    cin>>s;
    if(s[0]==s[1] && s[1]==s[2]) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
