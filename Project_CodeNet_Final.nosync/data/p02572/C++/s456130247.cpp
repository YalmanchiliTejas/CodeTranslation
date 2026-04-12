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
    vector<ll> newarr(n);
	ll sum = 0, temp; 

    ll res = 0;
    newarr[0] = A[n-1]%M;
    // sort(A.begin(),A.end());
    for (ll i = 1; i < n; i++) { 
        newarr[i] = (newarr[i-1] + A[n-i-1])%M;
        newarr[i] %= M;
    }

    for (ll i = 0; i < n-1; i++) { 
        sum += (A[i] * newarr[n-i-2])%M;
        sum %= M;
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
