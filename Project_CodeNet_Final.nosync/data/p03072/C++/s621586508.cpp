#include <bits/stdc++.h>
#define pb push_back
#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define ll long long int
#define ld long double
#define el '\n'
#define PI (ld)3.14159265358979323846
#define inf (ll)1000000000
#define mod (ll)1000000007
#define mod1 (ll)998244353
#define fo(i, n) for (long long i = 0; i < int(n); i++)
#define pll pair<ll, ll>
#define ff first
#define ss second
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define sz(a) a.size()
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

/*vector<int> parent, rak;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rak[a] < rak[b])
            swap(a, b);
        parent[b] = a;
        rank[a]+=rank[b];
    }
}*/

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

//vector<vector<ll>>v;
//vector<ll>vis,d;

int main() {
    IOS;
    cin>>n;
    ll a[n];p=-inf;
    fo(i,n){
        cin>>a[i];
        if(a[i]>=p)kv++;
        p=max(p,a[i]);
    }
    cout<<kv;
    return 0;
}