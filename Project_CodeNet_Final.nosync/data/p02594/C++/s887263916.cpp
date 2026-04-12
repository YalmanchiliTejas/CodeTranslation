#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 
//using namespace __gnu_pbds; 
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
#define standardVar ll n,m,i,j,k,num,num1,num2,flag=0
#define nn <<"\n"
#define __ <<" "<<
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define ittr(x,v) for(auto x=v.begin();x!=v.end();x++)
#define itr(x,n) for(x=0;x<n;x++)
#define itrab(x,a,b) for(x=a;x<b;x++)
#define itpr(v) ittr(x,v)cout<<*x<<" "; cout nn
#define itppr(v) ittr(x,v)cout<<(*x).ff<<" "<<(*x).ss<<"  "; cout nn
#define pi 3.14159265359
#define dTor(x) ((x)*pi)/180.0
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef map<ll,ll> ml;
typedef set<ll> sl;
typedef string str;
typedef pair<ll, ll> pl;
typedef vector< pl > vpl;
typedef map<pl,ll> mpl;
typedef set< pl > spl;
typedef vector<str> vst;
typedef vector<vl> vvl;

const ll M=1000000007;
const ll N=998244353;

ll power(ll x, ll y, ll p){     //MODULAR EXPONENTIATION
    ll res=1;
    x=x%p;
    if(x==0)
        return 0;
    while(y>0){
        if(y&1)
            res=(res*x)%p;
        y=y>>1;
        x=(x*x)%p;
    }
    return res;
}
ll inv(ll x, ll m){             //FERMAT INVERSE
    return power(x,m-2,m);
}
struct comp{                    //COMPARISON ON PAIRS
    template<typename T>        
    bool operator()(const T &a, const T &b){
        if (a.ff==b.ff)
            return (a.ss<b.ss);
        else
            return (a.ff<b.ff);
    }
};
bool mod(const pair<ll,ll> &a, const pair<ll,ll> &b){   //COMPARATOR FOR PAIRS (SORTING)
    if(a.ff!=b.ff)
        return (a.ff<b.ff);
    else
        return (a.ss<b.ss);
}
void sieve(vl &prime){          //SIEVE OF ERATOSTHENES
    ll maxN=1e6;
    vector<bool> pr(maxN+1,1);
    for(int i=2;i*i<=maxN;i++)
        if(pr[i]==1)
            for(int j=i*i;j<=maxN;j+=i)
                pr[j]=0;
    for(ll i=2;i<=maxN;i++)
        if(pr[i]==1)
            prime.pb(i);
}
bool isValid(ll i, ll j, ll n, ll m){   //CHECKS FOR OVERFLOW
    if(i>=0&&i<n&&j>=0&&j<m){
        return true;
    }
    return false;
}

//MAIN FUNCTION STARTS HERE

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    standardVar;
    int t;
    cin>>t;
    if(t>=30)
        cout<<"Yes" nn;
    else
        cout<<"No" nn;
    return 0;
}