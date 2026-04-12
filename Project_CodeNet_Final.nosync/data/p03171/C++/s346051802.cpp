#include <bits/stdc++.h>
#define PI 3.14159265359
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
typedef vector<pair<ll,ll> > vpii;
typedef vector<ll> vi;
const ll INF=1e13+7;
void input(ll *a,ll n){
    for(ll i=0;i<n;i++)cin>>a[i];
}
ll lcm(ll a,ll b){return (a*b)/__gcd(a,b);}
bool isprime(ll n){
    if(n==1)return false;
    if(n==2 || n==3)return true;
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}
//ll x[100001]={0};
ll a[200001]={0};
//ll b[100001]={0};
//bool c[1000001]={0};
//vector<pair<ll,ll> > adj[100001];
//vector<pair<pair<ll,ll>,ll> > edge;
//vector<ll> adj[200001];
//vpii edges;
////bool color[200001]={0};
//ll dist[100001]={0};

ll binary_expon(ll a,ll b){
    ll res=1;
    while(b){
        if(b%2)res=(res*a)%INF;
        a=(a*a)%INF;
        b/=2;
    }
    return res%INF;
}

void sieve(ll n,bool *a)
{
    for (ll p=2; p*p<=n; p++){
        if (!a[p]){
            for (ll i=p*p;i<=n;i+=p)
                a[i]=true;
        }
    }
}

ll fact(ll n){
    ll res=1;
    for(ll i=1;i<=n;i++)res*=i;
    return res;
}

double distance(ll x1,ll y1,ll x2,ll y2){
    return (sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}

/*void tree_dfs(ll curr,ll prev){
    for(auto u:adj[curr]){
        if(u!=prev){
            tree_dfs(u,curr);
        }
    }
}*/

/*void dfs(ll x,ll y){
    if(x<0 || y<0 || x>=n || y>=m)return;
    //if(grid[x][y]!=color)return;
    if(visited[x][y] || Map[x][y]=='#'){
        //f=true;
        return;
    }
    visited[x][y]=true;
    Map[x][y]='#';
    //if(px!=(x+1) || py!=y)
        dfs(x+1,y);
    //if(px!=(x-1) || py!=y)
        dfs(x-1,y);
    //if(px!=(x) || py!=y+1)
        dfs(x,y+1);
    //if(px!=(x) || py!=y-1)
        dfs(x,y-1);
}*/

/*bool isVowel(char c){
    return(c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}*/
//ll grid[1001][1001]={0};

/*void dfs(ll s){
    if(visited[s])return;
    visited[s]=true;
    for(auto u:adj[s]){
        dfs(u);
        dp[s]=max(dp[s],1+dp[u]);
    }
}*/
//set<pair<ll,ll> >edges;
/*vector<ll> z(string s) {
    ll n=s.length();
    vector<ll> z(n);
    ll x=0,y=0;
    for(ll i=1;i<n;i++) {
        z[i]=max(0ll,min(z[i-x],y-i+1));
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
            x = i; y = i+z[i]; z[i]++;
        }
     }
    return z;
}*/
ll dp[3001][3001];

void solve(){
    ll n;cin>>n;
    input(a,n);    

    for(ll i=0;i<n;i++){
        dp[i][i]=a[i];
    }

    for(ll i=n-1;i>=0;i--){
        for(ll j=i;j<n;j++){
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }

    cout<<dp[0][n-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //sieve(1000001,c);
    ll t=1;
    //cin>>t;
    for(ll i=0;i<t;i++){
        solve();
    }
}
