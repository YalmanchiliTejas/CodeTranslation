#include <bits/stdc++.h>
#define M 1000000007 
#define mod 1000000007
typedef long long ll;
using namespace std;

void solve() 
{ 
    ll n;
    cin>>n;
    vector<ll> A(n);
    for(ll i=0; i<n; ++i) cin>>A[i];
    ll sum = 0;
    ll psum = 0;
    for(auto x: A){
        sum += (psum*x)%M;
        psum += x;
        sum %= M;
        psum %= M;
    }
	cout<<sum%M;
} 



int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int q;
    q=1;
    // cin>>q;
    while(q--) solve();


    return 0;
}
