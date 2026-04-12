// Ayushman Tripathy, IIT Roorkee, CSE-23
#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define db double
#define fl float
#define endl '\n'

#define mod (ll)(1000000007)
#define mod1 (ll)998242353
#define mod2 (ll)998244353
#define PI 3.1415926535897932384626433832795

#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define pob pop_back

#define Sort(v) sort(v.begin(),v.end())
#define Sortd(v) sort(v.begin(),v.end(),greater<>())

#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;--i)
#define rf1(i,n) for(int i=n-1;i>=1;--i)
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repn(i,a,b) for(int i=a;i<=b;++i)

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vvi;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;

//NUMBER THEORY
//SIEVE
const int N=1e7+1;

vi sieve(int n){
    vi prime;
    vi pr(n+1);
    pr[0]=-1;
    pr[1]=-1;
    rep(i,2,n+1){
        if(pr[i]!=-1){
            pr[i]=1;
            for(int j=2*i;j<=n;j+=i){
                pr[j]=-1;
            }
        }
    }
    rep(i,1,n+1){
        if(pr[i]==1){
            prime.pb(i);
        }
    }
    return prime;    
}

vi min_prime_factor(int n){
    vi min_pf(n+1);
    rep(i,2,n+1){
        min_pf[i]=0;
    }
    min_pf[0]=2;
    min_pf[1]=-1;//Doesn't exist :(
    rep(i,2,n+1){
        if(min_pf[i]==0){
            for(int j=i;j<=n;j+=i){
                if(min_pf[j]==0)min_pf[j]=i;
            }
        }
    }
    return min_pf;
}

//factorise function will return a vector consisting of all the prime factors and number of times they occur
vpi factorise(int n){
    vi min_pf=min_prime_factor(n);
    vpi factors;
    int cnt=0,fac=1;
    while(n!=1){
        cnt=0;
        fac=min_pf[n];
        while(n%fac==0){
            cnt++;
            n/=fac;
        }
        factors.pb(mp(fac,cnt));
    }
    return factors;
}
//The above gives all prime factors of n in log(n) complexity and also the powers of each factor in the factorisation

//EULER-TOTIENT FUNCTION
vi PHI(int n){
    vi phi(n+1);
    phi[0]=0;
    phi[1]=1;
    rep(i,2,n+1){
        phi[i]=i;
    }
    rep(i,2,n+1){
        if(phi[i]==i){
            for(int j=i;j<=n;j+=i){
                phi[j]=phi[j]-phi[j]/i;//phi[i]=i(1-1/j1)(1-1/j2)(1-1/j3)... where j1,j2,j3.. are prime
            }
        }
    }
    return phi;
}
//nC2
ll C2(ll n){
    ll ans= max(((n*(n-1))/2),(ll)0);
    return ans;
}

//Square
ll sq(ll x){
    return x*x;
}

//Binary Exponentiation ((a^b)%m)
ll BinExp(ll a,ll b,ll m){
    ll res=1;   
    a%=m;
    while(b){
        if(b&1) res = (res * a)%m;
        b>>=1;
        a=(a*a)%m;
    }
    return res;
}

//GCD
ll gcd(ll a,ll b){
    if(b==0) return a;
    if(a<b)swap(a,b);
    return gcd(b,a%b);
}

ll gcdExtended(ll a,ll b, ll &x , ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll g=gcdExtended(b,a%b,x1,y1);
    x=y1;
    y=x1-((ll)(a/b))*(y1);
    return g;
}

ll mod_inv(ll a,ll m){
    ll x,y;
    ll g=(gcdExtended(a,m,x,y));
    if(g!=1)return -1;//{mod inv doesn't exist}
    else{
        ll ans = ((x%m)+m)%m;//(to make the value positive if negative x comes up from extended euclidean)
        return ans;
    }
}
//LCM
ll lcm(ll a, ll b){
    ll mul = a*b;
    if(a==0 || b==0)return 0;
    return (mul/gcd(a,b));
}

//********************************************************************************//
//GENERAL

//PAIR SORTING
//sort pair by second values
bool sortsec(const pair<ll,ll> &a, const pair<ll,ll> &b){ 
    return (a.second < b.second); 
}
//sort pair by first vals in descending
bool sortinrev(const pair<ll,ll> &a, const pair<ll,ll> &b){ 
    return (a.first > b.first); 
}
//String Hashing
ll compute_hash(string s){
    ll p=31,m = 1e9+9;
    ll hash=0,po=1;
    f(i,s.length()){
        hash=(hash+(s[i]-'a'+1)*po)%m;
        po=(po*p)%m;
    }
    return hash;
}
// vl h(2e6+7);//prefix hash
// vl po(2e6+7);//powers
// void compute_hash_array(string s){//same length substrings can be directly compared for their hash values now for equality if data set is not extremely large and hashes are unique
//     ll p=31,m=1e9+9;
//     po[0]=1;
//     f1(i,n+1)po[i]=(po[i-1]*p)%m;
//     h[0]=0;
//     f1(i,n+1){
//         h[i]=(h[i-1]+(s[i-1]-'a'+1)*po[i-1])%m;
//     }
//     //hash[l to r] =(((h[r+1]-h[l]+m)%m)*po[n-l])%m
// }

vl LPS(string s){
    int n=s.length();
    vl lps(n);
    f1(i,n){
        int j=lps[i-1];
        while(j>0 && lps[j]!=lps[i]){
            j=lps[j-1];
        }
        if(s[i]==s[j])++j;

        lps[i]=j;
    }
    return lps;
} 

//********************************************************************************//
//GRAPHS
const int V =4e5+5;
vvi adj(V);
vb vis(V);

//DFS
void dfs(int s){
    vis[s]=1;
    for(auto i:adj[s]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

//BFS
// const int V =4e5+5;
// vvi adj(V);
// vb vis(V);
// vi lvl(V);
// vi par(V);
// void bfs(int s){
//     queue<int> q;
//     q.push(s);
//     lvl[s]=1;
//     vis[s]=1;
//     int v;
//     while(!q.empty()){
//         v=q.front();
//         for(auto i:adj[v]){
//             q.push(i);
//             vis[i]=1;            
//             par[i]=v;
//             lvl[i]=lvl[v]+1;
//         }
//         q.pop();
//     }
// }

//UNION-FIND(DSU)
// const int V =4e5+5;
// vi par(V);
// vi size(V);
// void initialise(int n){
//     f1(i,n+1){
//         par[i]=i;
//         size[i]=1;
//     }
// }
// int root(int x){
//     while(par[x]!=x){
//         par[x]=par[par[x]];
//         x=par[x];
//     }
//     return x;
// }
// void union_find(int a,int b){//attaches smaller tree to bigger one
//     if(root(a)==root(b))return;
//     if(size[root(b)]>size[root(a)])swap(a,b);//a is the bigger rooted tree
//     size[root(a)]+=size[root(b)];
//     par[root(b)]=root(a);
// }

//**********************************************************************************//

//For Graphs
void solve_g(){
    int x,y;
    int n,m;
    cin>>n>>m;
    f(i,m){
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
}
void solve(){
    // #ifndef ONLINE_JUDGE
    // if(fopen("INPUT.txt","r"))
    // {
    // freopen ("INPUT.txt" , "r" , stdin);
    // freopen ("OUTPUT.txt" , "w" , stdout);
    // }
    // #endif 

    int t;
    cin>>t;
    f(p,t){
        

    }
}

int main(){
    fast;
    //solve();
    int x;
    cin>>x;
    if(x>=30)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}


