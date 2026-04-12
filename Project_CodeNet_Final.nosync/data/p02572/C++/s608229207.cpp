#include<bits/stdc++.h>
#define ll                 long long int
#define mod                1000000007
#define pi                 3.14159265358979323846264338327950288419716939937510
#define setbit(x)          __builtin_popcountll(x)
#define db                 long double
#define pp(x)              pair<x,x>
#define ff                 first
#define ss                 second
#define FIO                ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tc                 ll tc; cin>>tc; for(ll number = 1 ; number <= tc ; number ++ )
#define vv(x)              vector<x>
#define pb                 push_back
#define pob                pop_back
#define pf                 push_front
#define pof                pop_front
#define endl               "\n"
#define pq                 priority_queue
#define dbg(x)             { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y)          { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define bp                 ll kkk; cin >>kkk;
#define dbgArr(a,n)        cout<<"Array "<<#a<<endl; for(ll i=0 ; i<n ; i++) cout<<a[i]<<" "; cout<<endl;
#define maxE(a,n)          *max_element(a,a+n);
#define minE(a,n)          *min_element(a,a+n);
#define forn(i,s,n)        for(ll i=s ; i<n ; i++)
#define fornr(i,e,s)       for(ll i=e-1 ; i>=s ; i--)
#define arr1(a,n)          for(ll i=1;i<=n;i++){ cin>>a[i]; }
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define print cout<<"Case #"<<number<<": "
#define all(x) x.begin(), x.end()
ll power(ll x, ll b) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= mod;} b >>= 1; x *= x; x %= mod;} return p % mod;}
using namespace std;
# define INF 1e15

struct lex_compare {
    bool operator() (pp(ll) p1,pp(ll) p2){
        ll x1 = (p1.ff*(p1.ss-p1.ss/2));
        ll x2 = (p2.ff*(p2.ss-p2.ss/2));
        return x1 > x2;
    }
};

int main(){
    FIO;
    ll n; cin >> n;
    ll arr[n]; forn(i,0,n) cin >> arr[i];
    ll sum = 0;
    ll ans = 0;
    for(ll i = 0;i<n;i++){
        ll temp = ((arr[i]%mod)*sum)%mod;
        ans += (temp);
        sum += arr[i];
        sum %= mod;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}
