#include<bits/stdc++.h>
#include <string>
using namespace std;
#include<chrono>
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define foo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define max5(a,b,c,d,e)     max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e)     min(min3(a,b,c),min(d,e))
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
int mpow(int base, int exp); 
void ipgraph(int m);
void DFS(int n);
bool isprime(ll n);
int gcd(int a,int b);
void rstgraph(int n);

const int mod = pow(10,9)+7;
const int N = 3e5, M = N;

//=======================================================================================
vi g[N];
int vis[N];
int nodes=0;
// ll ans=0;
void iluzn() {
int n;
cin>>n;
vl a(n);
int i,j;
ll sum=0;
fo(i,n)  {cin>>a[i];sum+=a[i];}
ll pro=0;
fo(i,n-1){
  sum=sum-a[i];
 pro+=a[i]*(sum%mod);
 pro%=mod;
}
pro%=mod;
cout<<pro;
}

 
int main() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t=1,i;
    // cin>>t;
     while(t--) iluzn();
    return 0;
}
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
bool isprime(ll n){
    if(n<=1)
        return false;
    if(n==2)
        return true;
    if(n%2==0)
        return false;
    ll rt = sqrt(n);
    for(ll i=3;i<rt;i+=2){
        if(n%i==0)
            return false;
    }
    return true;
}
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 
void ipgraph(int m){
  int u, v;
  while(m--){
    cin>>u>>v;
    g[u].pb(v);
    // g[v].pb(u);
  }
}

void DFS(int n)
{  ++nodes;
    vis[n] = 1;
    for(vector<int>::iterator i = g[n].begin(); i != g[n].end() ; i++)
    {
        if(!vis[*i])
            DFS(*i);
    }
}
void rstgraph(int n){
  int i;
  fo(i,n+1){
    g[i].clear();
    vis[i]=0;
  }
  nodes=0;
}