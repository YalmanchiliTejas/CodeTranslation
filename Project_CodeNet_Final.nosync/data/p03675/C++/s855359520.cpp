#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <ll, ll> P;

const ll MOD=1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll a[n];
    rep(i,0,n) cin>>a[i];
    deque<ll> q;
    rep(i,0,n){
        if(i%2) q.push_front(a[i]);
        else q.push_back(a[i]);
    }
    if(n%2) rev(q);
    rep(i,0,n){
        if(i==n-1) cout<<q[i]<<"\n";
        else cout<<q[i]<<" ";
    }
}