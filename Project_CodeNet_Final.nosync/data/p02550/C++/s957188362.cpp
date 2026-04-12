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
struct ppp{
    ll a,b,c;
};
struct lex_compare {
    bool operator() (ppp p1, ppp p2){
        if(p1.a == p2.a){
            if(p1.b == p2.b) return p1.c < p2.c;
            else return p1.b < p2.b;
        }else{
            return p1.a < p2.a;
        }
    }
};


int main(){
    FIO;
    ll n, x, m; cin >> n >> x >> m;
    map<ll,pp(ll)> me;
    ll ans = 0;
    ll j = n;
    while(j > 0){
        if(me.count(x) == 0){
            me[x] = {j, ans};
            ans += x;
            j--;
        }else{
            pp(ll) temp = me[x];
            ll stepr = temp.ff-j;
            ll diff = ans-temp.ss;
            ans += (diff)*(j/stepr);
            j -= (j/stepr)*(stepr);
            if(j > 0){
                ans += x;
                j--;
            }
        }
        x = (x*x)%m;
    }
    cout << ans << endl;
    return 0;
}
