// kid_kb //

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long int
#define lower(str) transform(str.begin(),str.end(),str.begin(),::tolower);
#define upper(str) transform(str.begin(),str.end(),str.begin(),::toupper);
#define mod 1000000007
#define SORT(vec) sort(vec.begin(),vec.end());
#define pb push_back
#define csb __builtin_popcount
#define msb(n) (ll)(log2(n))
#define DIG(n) floor(log10(n))+1
#define kb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ptr(arr) for(auto i:arr)cout<<i<<" ";
#define ptr2(vec) for(auto i:vec){for(auto j: i){cout<<j<<" ";}cout<<endl;}
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,n,a) for (int i=n-1;i>=a;i--)
#define mem(a,val) memset(a,val,sizeof(a))
#define INF INT_MAX
#define inf INT_MIN

// cout<<fixed<<setprecision(8)<<endl;

ll gcd(ll a,ll b)
{    if (a == 0)    return b;     return gcd(b % a, a); }

ll lcm(ll a,ll b)
{    ll g=gcd(a,b); ll ans=(a*b)/g; return ans;    }

ll fastpower(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=fastpower(a,b/2,m); t=(t*t)%m; if(b&1)t=(t*a)%m; return t;}

ll modInverse(ll a, ll m) { return fastpower(a, m-2, m); }

//----------------------------------------Let's Fight-----------------------------------------------------------------

void solve(){
    ll n,x,m;
    cin>>n>>x>>m;
    if(x==0 or m==0){cout<<0<<endl;return;}
    ll sum=0;
    vector<ll>v;
    set<ll>s;
    int i;
    for(i=0;i<n;i++){
        if(s.find(x)!=s.end())break;
        sum+=x;
        s.insert(x);
        v.pb(x);
        x*=x;
        x%=m;
    }
    if(i==n){cout<<sum<<endl;return;}
    ll left=n-i;
    ll j=0;
    for(auto k:v){
        if(k==x)break;
        j++;
    }
    ll bche=v.size()-j;
    if(bche==0){cout<<sum<<endl;return;}
    ll mul=left/bche;
    ll add=left%bche;
    ll ts=0,cs=0;
    for(;j<v.size();j++){
        ts+=v[j];
        if(add){
            cs+=v[j];
            add--;
        }
    }
    sum=sum+cs+mul*ts;
    cout<<sum<<endl;
}

int main()
{
    kb
//  clock_t tStart = clock();
    ll t;
     t=1;
//    cin>>t;
    while(t--){
        solve();
    }
//  printf("%.2fs time lga\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
