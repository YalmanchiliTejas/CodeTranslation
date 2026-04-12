#include <bits/stdc++.h>
#define ll                  long long
#define pb                  push_back
#define pf                  push_front
#define mp                  make_pair
#define in                  insert
#define sz(a)               (int)(a).size()
#define all(x)              (x).begin(), (x).end()
#define fore(i,a,b)         for(ll i=a; i<b; i+=1)
#define forr(i,a)           for(ll i=a; i>=0; i-=1)
#define forg(i,b,e,c)       for (ll i=(ll)b; i<(ll)e; i+=c)
#define ford(i,a)           for(auto i=a.begin(); i!=a.end(); i++) 
#define F first
#define S second
#define clr(a,val)          memset(a,val,sizeof (a))
#define min3(a, b, c)       min(min(a, b), c)
#define min4(a, b, c, d)    min(min(a, b), min(c, d))
#define max3(a, b, c)       max(max(a, b), c)
#define max4(a, b, c, d)    max(max(a, b), max(c, d))
#define endl "\n"
#define printV(arr)         fore(x,0,sz(arr)) cout << arr[x] <<" "; cout<<endl;
#define printR(arr,a,b)     fore(x,a,b) cout << arr[x] <<" "; cout<<endl;
#define setp(x)             fixed<<setprecision(x)
 
 
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll,ll> lll;
typedef vector<ii> vii;
typedef vector<lll> vlll;
typedef pair<string, int> si;
typedef pair<int, string> is;
typedef vector<string> vs;
const int MAX=1e5+10;
const int MOD=1000000007;
const double pi=acos(-1);
const int dx[]={0,1,-1,0};
const int dy[]={-1,0,0,1};
const int dxc[]={0,2,-2,0,2,2,-2,-2};
const int dyc[]={-2,0,0,2,-2,2,-2,2};
 
ll min(ll a, ll b){
    if(a>b) return b;
    return a;
}
ll max(ll a, ll b){
    if(a>b) return a;
    return b;
}
 
ll gcd(ll a, ll b){
    while(b!=0){
        a%=b;
        swap(a,b);
    }
    return a;
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a,b);
}
bool isPrime(ll n){
    if(n<=1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    for(ll i=3; i*i<=n; i+=2){
        if(n%i==0) return false;
    }
    return true;
}
 
set<ll> gen(ll n){
    set<ll> divs;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            divs.insert(i);
            divs.insert(n/i);
        }
    }
    return divs;
}
 
map<ll, int> fact(ll n){
    map<ll, int> F;
    for(ll p = 2; p*p <= n; p++){
        while(n%p == 0){
            F[p]++;
            n /= p;
        }
    }   
    if(n > 1) F[n]++;
    return F;
}
 
ll sum(ll n){
    return (n*(n+1))/2;
}
 
ll binaryExp(ll a, ll b, ll c){
    if(b==0) return 1;
    if(b%2==0){
        ll temp=binaryExp(a,b/2,c);
        return (temp*temp)%c;
    }
    else{
        ll temp=binaryExp(a,b-1,c);
        return (temp*a)%c;
    }
}
 
bool isPal(string& cad){
    int p1=sz(cad)-1;
    fore(i,0,sz(cad)/2){
        if(cad[i]!=cad[p1]) return false;
        p1--;
    }
    return true;
}

double dis(double x1,double y1, double x2, double y2){
    double ff=pow(x2-x1,2)+pow(y2-y1,2);
    return sqrt(ff);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; cin>>n;
    vi vec(n);
    vll acum(n+1);
    fore(i,0,n) cin>>vec[i];
    acum[n]=0;
    forr(i,n-1) acum[i]=(vec[i]+acum[i+1])%MOD;
    ll res=0;
    fore(i,0,n-1){
        ll act=(vec[i]*acum[i+1])%MOD;
        res+=act%MOD;
    }
    cout<<res%MOD<<endl;

    return 0;
}