#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define tc() ll T;cin>>T;while(T--)
#define pb push_back

struct cmp {
    bool operator() (const pair<ll,ll> &a,const pair<ll,ll> &b){
        return a.first>b.first;
    }
};

int main() {
    
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    /*-----------------Code Begins Here------------------*/
    
    ll x; cin>>x;
    if(x>=30) cout<<"Yes\n";
    else cout<<"No\n";
    
    /*------------------Code Ends Here-------------------*/
    
    return 0;
}