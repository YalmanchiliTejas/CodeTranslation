// #pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define N 1000000007
#define N2 998244353
#define nmax 200001
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(ll i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define fill_nums(A,n) for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].insert(b-1); adj[b-1].insert(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].insert(b-1);}

vector<ll> B(nmax,0);

int main() {
    
    ll n;
    cin>>n;

    multiset<ll> se;
    for(int i=0;i<n;i++) {
        ll a;
        cin>>a;

        multiset<ll>::iterator it = se.lower_bound(a);
        if(i==0 || it == se.begin())
            se.insert(a);
        else {
            it--;
            se.erase(it);
            se.insert(a);
        }
    }
    cout<<se.size()<<endl;

    return 0;
}


