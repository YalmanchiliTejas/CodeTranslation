#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define fi first
//#define endl "\n"
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define initialize(array,size,value) for(ll i=0;i<size;i++) array[i]=value
#define couta(array,size) for(ll i=0;i<size;i++) cout<<array[i]<<" "
#define debug(x) cout<<"x: "<<x<<endl
#define dbug(x,y) cout<<"x: "<<x<<"    "<<"y: "<<y<<endl
#define inf (long long int) 1e18
#define eps 0.000001
#define vl vector<ll> 
#define sl set<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll> 
#define pq priority_queue<ll>
#define mod 1000000007
#define MAXN 100001
typedef tree<pll,null_type,less<pll>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
ll spf[MAXN]; 
ll gcd(ll a,ll b);
ll palindrome(string s);
ll modexp(ll a,ll b,ll m);
void sieve();
ll ceil(ll a, ll b);
vl getFactorization(ll x);
void getZarr(string str, ll Z[]);
vector<ll> prefix_function(string s);


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/
        
    ll n;
    cin>>n;
    ll a[n];
    loop(i,0,n){
        cin>>a[i];
    }
    ll ans=0;
    loop(i,0,n){
        bool done=true;
        loop(j,0,i){
            if(a[j]>a[i]){
                done=false;
            }
        }
        if(done==1) ans++;
    }
    cout<<ans<<endl;
}

ll gcd(ll a, ll b){
    if (a == 0)   return b;
    if(b==0)      return a;
    if (a == b)   return a;
    if (a > b)    return gcd(a%b, b);
    return gcd(a, b%a);
}

ll palindrome(string s){
    ll l = 0;
    ll h = s.length() - 1;
    while (h > l){
        if (s[l++] != s[h--]){
            return 0;
        }
    }
    return 1;
}

ll modexp(ll a, ll b, ll m){
    if (b==0)
        return 1;
    ll temp = modexp(a,b/2,m);
    temp = (temp*temp)%m;
    if (b&1)
        return (temp*(a%m))%m; // if b is odd a^b = a^(b/2)*a^(b/2)*a
    return temp;
}

void sieve() { 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<MAXN; i++) { 
        if (spf[i] == i) { 
            for (ll j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
