#include <bits/stdc++.h>
//#include <boost/lexical_cast.hpp>
using namespace std;
  #define ll  long long
    #define rep(i,n) for(ll i=0;i<n;i++)
    #define pb push_back
    #define in insert
    #define pll pair<ll,ll>
    #define mll map<ll,ll>
    #define si set<ll>
    #define sc set<char>
    #define msi multiset<ll>
    #define msc multiset<char>

    
   // #define bs  binary_search
    #define rep1(x,n) for(ll x=n-1;x>=0;x--) 
    #define for1(i,a,n) for(ll i=a;i<n;i++)
    #define for2(i,a,n) for(ll i=n-1;i>=a;i--)
    #define F1 first
    #define S2 second
    #define vi vector<ll>
    #define vii vector<vector<ll>>
    #define vpi vector<pll>
    #define SORT(x) sort(x.begin(),x.end())
    #define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
    #define All(x) (x).begin(),(x).end()
    #define rAll(x) (x).rbegin(),(x).rend()
    #define db  double
    #define S size()
    #define EN end()
    #define BE begin()
    #define LEN length()
    #define itr(s) for(auto x:s)

    
    const ll MAX=1e9+1;
    
    const double pi=3.1415926535897932384626433832;
    const ll M=1e9 +7;
    ll bis(ll a[],ll l,ll r,ll x){
     while(l<=r){
      ll m=l +(r-l)/2;
      if(a[m]==x)
      return m;
      if(a[m]<x)l=m+1;
      else r=m-1;
     }
     return -1;
    }
    
    ll gcd(ll x,ll y){
        if(x==0)return y;
        else return gcd(y%x,x);
    }
    ll lcm(ll x,ll y){
        return (x*y)/gcd(x,y);
    }
   
bool isPrime(ll n) 
{  
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (ll i = 5; i * i <= n; i = i + 6){ 
        if (n % i == 0 || n % (i + 2) == 0){ 
            return false; 
        }
    }
    return true; 
} 
bool pdrome(string s){
    ll n = s.length();
    for(ll i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            return false;
        }
    }
    return true;
}
string need(string s){
    string a=s;
    reverse(a.begin(),a.end());
    a=s+'?'+a;
    ll n=a.size();
    ll pref[n];
    memset(pref,0,sizeof(pref));
    //ll len=0;
    for1(i,1,n+1){
        ll len=pref[i-1];
         while(len>0&&a[len]!=a[i])len=pref[len-1];
         if(a[i]==a[len])len++;
         pref[i]=len;
    }
    //cout<<pref[n-1];
    return a.substr(0,pref[n-1]);
}

ll mindig(ll x){
    ll ans = 9;
    ll t = x;
    while(x){
        ans = min(ans,x%10);
        x/=10;
    }
    x = t;
    return ans;
}
ll maxdig(ll x){
    ll ans = 0;
    ll t = x;
    while(x){
        ans = max(ans,x%10);
        x/=10;
    }
    x = t;
    return ans;
}
ll modpow(ll x,ll n,ll M){
    if(n==0)return 1%M;
    ll u=modpow(x,n/2,M);
    u=(u*u)%M;
    if(n%2==1)u=(u*x)%M;
    return u;

}
ll sumdigits(ll a) {
    ll result = 0;
    while (a > 0) {
        result += a % 10;
        a /= 10;
    }
    return result;
}
ll digits(long long n) 
{ 
    return floor(log10(n) + 1); 
}
const ll Node=1e5+7;
vi adj[Node];
bool vis[Node];
void addedge(ll u,ll v){
    adj[u].pb(v);
    adj[v].pb(u);
}
void bfs(ll u){
    vis[u]=true;
    list<ll>q;
    q.pb(u);
    while(!q.empty()){
        //cout<<q.front()<<" ";
        q.pop_front();
        for(auto x:adj[u]){
            if(!vis[x]){
                vis[x]=true;
                q.pb(x);
            }
        }
    }
}
void dfs(ll u){
    vis[u]=true;
    for(auto x:adj[u]){
        if(!vis[x]){
        dfs(x);
        }
    }
}
ll con1(string s){
    long long res=0;
    stringstream geek(s); 
    geek>>res;
    return res;
    
}
string con2(ll num){
    
    string stri=to_string(num);
    return stri;   
}


//string stri = boost::lexical_cast<string>(i_val); 
const ll N=1e9+7;

void solve(){
      string ss;
    cin>>ss;ll cnt=0,cnt2=0;
    for1(i,0,3){
      if(ss[i]=='A')cnt++;
      //else cnt2++;
    }//cout<<cnt;
    if(cnt==3||cnt==0)cout<<"No\n";
    else cout<<"Yes\n";
  }

int main(){
        
        #ifndef ONLINE_JUDGE
               freopen("input.txt","r",stdin);
               freopen("output.txt","w",stdout);
               #endif
               ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
      ll t=1;
      //cin>>t;
    
      while(t--){
         
           solve();
      } 
      
        return 0;
}
