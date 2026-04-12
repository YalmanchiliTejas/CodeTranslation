#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
//using namespace __gnu_pbds;
#define rep(i,a,b) for(i=(a);i<=(b);i++)
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define maxn 100005
#define inf 1e18
#define boost ios::sync_with_stdio(false);cin.tie(0)
#define fr freopen("source.txt","r",stdin),freopen("output.txt","w",stdout)
#define SET(a,b) memset(a,b,sizeof(a))
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define ps(x,y) fixed<<setprecision(y)<<x
//template<typename T>
//using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
    return out <<  "(" << a.F << ", " << a.S << ")";
}
 
template<class A> ostream& operator << (ostream& out, const vector<A> &a) {
    out << "[";
    for (auto it = a.begin(); it != a.end(); ++it) {
        if (it != a.begin())
            out << ", ";
        out << *it;
    }
    return out << "]";
}
const int N=3001;
ll dp[N][N][2],a[N];
ll go(ll i,ll j,ll cur){
    if(i>j) return 0;
    ll &ans=dp[i][j][cur];
    if(ans!=-1) return ans;
    if(cur==0){
        ans=0;
        ans=max(ans,a[i]+go(i+1,j,1));
        ans=max(ans,a[j]+go(i,j-1,1));
    }
    else{
        ans=inf;
        ans=min(ans,go(i+1,j,0));
        ans=min(ans,go(i,j-1,0));
    }
    return ans;
}
int main()
{
    boost;
    ll n,i,j,x,t,y;
    cin>>n;
    ll s=0;
    for(i=0;i<n;i++) cin>>a[i],s+=a[i];
    SET(dp,-1);
    x=go(0,n-1,0);
    cout<<2*x-s;
}