#include<bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define M        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,m;
    cin>>n>>m;
    
    string s[n];
    
    for(ll i=0; i<n; i++) cin>>s[i];
    
    bool g[n]={false}, h[m]={false};
    
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(s[i][j]=='#'){
                g[i]=true; h[j]=true;
            }
        }
    }

    for(ll i=0; i<n; i++){
        if(g[i]) for(ll j=0; j<m; j++){
           if(h[j]) cout<<s[i][j];
        }
        if(g[i]) cout<<endl;
    }
    
    return 0;
}
