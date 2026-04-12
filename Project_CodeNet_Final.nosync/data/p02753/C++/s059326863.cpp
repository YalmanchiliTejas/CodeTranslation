#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define ff first
#define ss second
bool comp(ll a,ll b){
    return a > b;
}

bool check(vector<ll> &a,ll k){
    ll n = a.size();
    
    for(ll i=0;i<n-1;i+=2){
        ll x = max(a[i],a[i+1]);
        k-=x;
        if(k<0) return false;
    }
    
    if(n&1){
        k-= a[n-1];
    }
    if(k<0) return false;
    return true;
    
}

void solve()
{
    string s;cin>>s;
    set<char> st;
    for(ll i=0;i<s.size();i++){
        st.insert(s[i]);
    }
    if(st.size()>1){
        cout<<"Yes\n";
    }
    else
        cout<<"No";
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ll t;cin>>t;while(t--)
        solve();
    
}