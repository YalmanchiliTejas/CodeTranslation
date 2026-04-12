#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//template<typename T>
#define o_set(T) tree<T, null_type,greater<T>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//use it like o_set(ll) x;  --> x.order.....
//-->for pair<ll,ll> : second element as index and for search use INT_MAX...
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set


#define fast ios::sync_with_stdio(false);cin.tie(0);cout<<setprecision(25)
#define pb push_back
#define I insert
#define F first
#define S second
#define digit(x) floor(log10(x))+1
const long long M1=1000000007;
const long long  M2=998244353;
#define L_MAX 1e18
using ll = long long;
using ld = long double;
using ii = pair<ll,ll>;
using matrix = vector<vector<ll>>;
using arr = vector<ll>;
using vs = vector<string>;
using pv = vector<ii>;
#define in1(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld %lld",&x,&y)
#define all(x) x.begin(),x.end()
#define debug(x) cerr << #x << " is " << x << endl;
template<typename T>
void showArr(T a){
    for(auto i : a) cout<<i<<" ";
    cout<<endl;
}
bool isValid(ll x,ll y,ll n,ll m){
    return (x>=0 and y>=0 and x<n and y<m);
}
ll power(ll a,ll n,ll m){
    ll ans=1;
    while(n>0){
        if(n&1){
            ans=(ans%m * a%m)%m;
        }
        n=n>>1;
        a=(a%m*a%m)%m;
    }
    return ans;
}
ll MMI(ll a,ll m){
    ll m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1){
        ll q=a/m,t=m;
        m=a%m,a=t,t=y,y=x-q*y,x=t;
    }
    if(x<0) x+=m0;
    return x;
}

ll dx[]={-1,1,0,0},dy[]={0,0,-1,1};
//ll dx[]={-1,1,-1,1,0,0,-1,1} , dy[]={-1,1,0,0,-1,1,1,-1};
int main(){
    fast;
    ll t;
    cin>>t;
    if(t>=30){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    
    
    return 0;
}