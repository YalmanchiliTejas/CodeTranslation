#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;
typedef vector<pii> vpii;

#define pb(x) push_back(x)
#define ppb() pop_back()
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
#define FOR0(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORD(i,a,b) for(ll i=(a);i>=(int)(b);i--)
#define sf(n) scanf("%lld", &n)
#define sfc(x) scanf("%c", &x)
#define pf(x) printf("%lld", x)
#define pff(x) printf("%lf", x)
#define pfc(x) printf("%c", x)
#define pfs(x) printf("%s", x)
#define sf2(a,b) scanf("%lld %lld", &a, &b)
#define sf3(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define pfn(n) printf("%lld\n", n)
#define pfs(n) printf("%lld ", n)
#define ff first
#define ss second
#define mem(a,b) memset(a,b,sizeof(a))
#define sz size()
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

bool prime[500010];
void SieveOfEratosthenes(ll n)
{
    memset(prime,true, sizeof(prime));

    for (ll p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
}

ll power(ll x,ll y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
}

ll power1(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1){
            res*=a;
        }
        a=a*a;
        b>>=1;
    }
    return res;
}



ll mod_power(ll a,ll b,ll m){
    ll res=1;
    a%=m;
    while(b){
        if(b&1){
            res=res*a%m;
        }
        a=a*a%m;
        b>>=1;
    }
    return res;
}
ll printDivisors(ll n) 
{ 
    ll count=0;
    for (ll i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                count++; 
  
            else // Otherwise print both 
                printf("%d %d ", i, n/i); 
        } 
    } 
} 
bool isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}
ll par[1000001];
ll ranki[1000001]={0};

ll find(ll x){
    if(par[x]!=x){
        par[x] = find(par[x]);
    }
    return par[x];
}

void unionset(ll x,ll y){
    ll xr = find(x);
    ll yr = find(y);
    if(ranki[xr]>ranki[yr]){
        par[yr]=xr;
    }
    else if(ranki[xr]<ranki[yr]){
        par[xr]=yr;
    }
    else{
        par[yr] = xr;
        ranki[xr]++;
    }
}

vector<ll> v[100001];
ll vis[100001]={0};
void dfs1(ll s){
    vis[s]=1;
    FOR0(i,v[s].size()){
        if(!vis[v[s][i]]){
            dfs1(v[s][i]);
        }
    }
}

void dfs(ll s){
    stack<ll> st;
    st.push(s);
    vis[s]=1;
    while(!st.empty()){
        ll u = st.top();
        st.pop();
        FOR0(i,v[u].size()){
            if(!vis[v[u][i]]){
                st.push(v[u][i]);
                vis[v[u][i]]=1;
            }
        }
    }
}

int main(){
    fast
    ll n;
    cin>>n;
    ll a[n];
    FOR0(i,n)cin>>a[i];
    ll count=0;
    ll maxi = 0;
    FOR0(i,n){
        if(a[i]>=maxi){
            maxi = a[i];
            count++;
        }
    }
    cout<<count<<endl;
}