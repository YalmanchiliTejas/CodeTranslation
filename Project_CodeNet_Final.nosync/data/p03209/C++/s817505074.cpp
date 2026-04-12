#include <bits/stdc++.h>
#define pb push_back
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define ll long long int
#define ld long double
#define el '\n'
#define PI (ld)3.141592653589793238462643383279502884197169399375105820974944
#define inf (ll)1000000000
#define mod (ll)1000000007
#define mod1 (ll)998244353
#define fo(i, n) for (long long i = 0; i < int(n); i++)
#define pll pair<ll, ll>
#define ml map<ll,ll>
#define vli vector<pair<ll,int>>
#define vpl vector<pll>
#define vvl vector<vector<ll> >
#define vvpl vector< vector<pll> >
#define ff first
#define ss second
#define pqueue priority_queue< ll >
#define pdqueue priority_queue< ll,vl ,greater< ll > >
#define mem(a,b) memset(a,b,sizeof(a));
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define sz(a) (ll)a.size()
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define vl vector<ll>
//#define x ff
//#define y ss
#define pt(a) for(auto it:a)cout<<it<<" ";cout<<endl;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
using namespace std;

double gcd(double a, double b) { return a < 0.01 ? b : gcd(fmod(b, a), a); }

vector<ll> parent, rak;

void make_set(int f){
    fo(i,f+1)parent.pb(i);
    rak.assign(f+1,1);
}

ll find_set(ll v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

ll union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rak[a] < rak[b])
            swap(a, b);
        parent[b] = a;
        rak[a]+=rak[b];
        return (rak[a]-rak[b])*(rak[b]);
    }
    return 0;
}

long long bpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % m;
      a = a * a % m;
      b >>= 1;
  }
  return res;
}
ll extend_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll ans =extend_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;

    return ans;
}
ll inverse(ll a,ll m){
    ll x,y;
    extend_gcd(m,a,x,y);
    y%=m;
    y+=m;
    y%=m;
    return y;
}

/*const int N = 1000001;
int lp[N+1];
vector<int> pr;
void s(){
for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}*/


ll kv;
ll t,n,x,y,h,k,z,p,q,w;
string s;
//vvl v;
vl vis,d;


ll sg(ll x,ll y){
    if(y==0)return 0;
    else if(x==0&&y==1)return 1;
    y--;
    ll ans=0;
    if(y>=powl(2,x+1)-3){
        y-=powl(2,x+1)-3;
        ans+=powl(2,x)-1;
    }
    else{
        return sg(x-1,y);
    }
    if(y>0)y--,ans++;
    else return ans;
    if(y>=powl(2,x+1)-3){
        y-=powl(2,x+1)-3;
        ans+=powl(2,x)-1;
    }
    else{
        return ans+sg(x-1,y);
    }
    return ans;
}

int main() {
    IOS;
    cin>>n>>k;
    cout<<sg(n,k);
    return 0;
}
