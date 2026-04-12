#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define mod 1000000007ll
#define mod1 998244353ll
#define endl '\n'
#define inf ((ll)1e18+1)
#include<chrono>
using namespace chrono;
mt19937_64 rng(high_resolution_clock::now().time_since_epoch().count());
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
#define debr(x,y) {cout<<"-->  "<<#x<<" to "<<#y<<" :  "; auto itr=x; while(itr!=y) cout<<(*itr++)<<' '; cout<<endl; }
#define deba(x) {cout<<"-->  "<<#x<<" :  "; for(auto ele:(x)) cout<<ele<<"  "; cout<<endl; }
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout<<endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a <<"  ,  ";
    err(++it, args...);
}

ll func(ll &val,ll &m){
    ll sq=val*val;
    return sq%m;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n,X,m;
    cin>>n>>X>>m;
    vector<ll> ar;
    ar.push_back(X);
    set<ll> st;
    ll cur=X;
    st.insert(cur);
    while(ar.size()<n){
        cur=func(cur,m);
        if(st.find(cur)!=st.end())break;
        ar.push_back(cur);
        st.insert(cur);
    }
    ll sz=ar.size();
    ll ans=0;
    // deba(ar)return 0;
    if(ar.size()>=n){
        for(ll x=0;x<n;x++){
            ans+=ar[x];
        }
    }else{
        ll taken=0;
        ll x=0;
        for(x=0;taken<n && ar[x]!=cur;x++){
            taken++;
            ans+=ar[x];
        }
        // deb(x,taken)return 0;
        ll rem=n-taken;
        ll sum=0;
        ll y=x;
        while(x<sz){
            sum+=ar[x++];
        }
        ll tt=sz-taken;
        ll times=rem/tt; //CHECK
        ans+=times*sum;
        rem%=tt;
        while(rem--){
            ans+=ar[y++];
        }
    }

    cout<<ans<<endl;
}
