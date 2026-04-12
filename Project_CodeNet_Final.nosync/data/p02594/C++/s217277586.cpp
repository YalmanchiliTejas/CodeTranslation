#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define popb pop_back()
#define mp make_pair
#define le length()
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0,lim-1);
  return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];




 

int maxi(int a, int b){
  if(a>b)return a;
  return b;
}

  
void SieveOfEratosthenes(int n , vector<ll>& pr) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          pr.push_back(p);
} 

void minimumBribes(vector<ll> A) 
{
    int n = A.size();
    int cnt = 0;
    ll sum = 0;
    for(int i = n - 1; i >= 0; i--)
    {
      
        if(A[i] != (i + 1))
        {
            if(((i - 1) >= 0) && A[i - 1] == (i + 1))
            {
                cnt++;
                sum+=1000;
                swap(A[i], A[i-1]);
            }
            else if(((i - 2) >= 0) && A[i - 2] == (i + 1))
            {
                cnt += 1;
                A[i - 2] = A[i - 1];
                A[i - 1] = A[i];
                A[i] = i + 1;
                sum+=2000;
            }
            else
            {
                printf("Too Much\n");
                return;
            }
        }      

    }
    if(cnt!=0)cout<<sum/cnt<<'\n';
        else cout<<0<<"\n";
    return;
}

void swapi(ll& a, ll&b){
  ll temp = a;
  a = b;
  b = a;
}
ll sumof(ll n){
  ll sum =0;
  for(ll i = 1;i<=n;i++)sum+=i;
    return sum;
}

void bfs(vector< vector<int> >& g , vector<int>& dist){
  dist[0] = 0;
  queue<int> q;
  q.push(0);
  vector<bool> visited(g.size(),false);
  while(!q.empty()){
    int temp = q.front();
    q.pop();
    if(visited[temp])continue;
    visited[temp] = true;
    //cout<<temp<<'\n';
    for(auto it:g[temp]){
      if(!visited[it]){
        //cout<<it<<" ";
        if(temp<it)
        dist[it] = dist[temp] +1;
        else dist[it] = dist[temp];
        q.push(it);
      }
    }
    //cout<<endl;
  }
}

void solve(){
 int n;cin>>n;
 if(n>=30)cout<<"Yes\n";
 else cout<<"No\n";

}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
     #ifndef ONLINE_JUDGE
          freopen("input.txt", "r", stdin);
          freopen("output.txt", "w", stdout);
    #endif
          int t;
          t = 1;
          //cin>>t;
          int tt = t;
    while(t--) {
       //cout<<"Case #"<<tt-t<<": \n";
     solve();     //cout<<"done bro\n";
     //cout<<"\n"; 
     
    }
    //cout<<"chal rha h";

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

void ipgraph(int n, int m){
  int i, u, v;
  while(m--){
    cin>>u>>v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
}

void dfs(int u, int par){
  for(int v:g[u]){
    if (v == par) continue;
    dfs(v, u);
  }
}