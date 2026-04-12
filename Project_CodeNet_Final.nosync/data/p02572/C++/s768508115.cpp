#include<bits/stdc++.h>

using namespace std;

#define ll 				long long
#define fr(i,x,n) 		for(int i=x; i<n; ++i)
#define frr(i,n) 		for(int i=n; i>=0; --i)
#define all(x) 			x.begin(), x.end()
#define sortall(x) 		sort(all(x))
#define null 			NULL
#define mod             1000000007
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;
typedef vector<int>     vi;
typedef vector<ll>      vl;

void solve()
{
    int n;
    cin>>n;
    vi A(n);fr(i, 0, n) cin>>A[i];
    vl suffix(n);
    suffix[n-1]=A[n-1];
    frr(i, n-2) suffix[i]=(A[i]+suffix[i+1])%mod;
    ll result=0;
    fr(i, 0, n-1)
    {
        result+=(A[i]*suffix[i+1])%mod;
        result=result%mod;
    }
    cout<<result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}