#include<bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
ll modpow(ll a, ll b){
 
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b/2;
    }
    return ans;
}
 
 
int main(){
 
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    int n,m;
    cin>>n>>m;
 
    if(n == m) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
 
 
}