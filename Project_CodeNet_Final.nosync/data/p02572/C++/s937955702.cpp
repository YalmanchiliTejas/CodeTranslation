#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define db double
#define fl float
#define endl '\n'

#define mod (ll)(1000000007)
#define mod1 (ll)998242353
#define mod2 (ll)998244353
#define PI 3.1415926535897932384626433832795

#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define pob pop_back

#define Sort(v) sort(v.begin(),v.end())
#define Sortd(v) sort(v.begin(),v.end(),greater<>())

#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;--i)
#define rf1(i,n) for(int i=n-1;i>=1;--i)
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repn(i,a,b) for(int i=a;i<=b;++i)

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;

//nC2
ll C2(ll n){
    ll ans= max(((n*(n-1))/2),(ll)0);
    return ans;
}
//square
ll sq(ll n){
    return n*n;
}

//GCD
ll gcd(ll a,ll b){
    if(a<b){
        swap(a,b);
    }
    if(b==0){
        return a;
    }    
    else{
        return gcd(b,a%b);
    }
}

//sort pair by second values
bool sortsec(const pair<ll,ll> &a, const pair<ll,ll> &b){ 
    return (a.second < b.second); 
}


//Binary Exponentiation
ll BinExp(ll a, ll b, ll m){
    a%=m;
    ll res =1;
    while(b>0){
        if(b&1){
            res = (res * a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll a[n];
    f(i,n)cin>>a[i];
    ll ss[n]={0};
    ss[n-1]=a[n-1];
    rf(i,n-1){
        ss[i]=(ss[i+1]+a[i])%mod;
    }
    ll ans=0;
    f(i,n-1){
        ans=((a[i]*ss[i+1])%mod+ans)%mod;
    }
    cout<<ans<<endl;


    return 0;
}

