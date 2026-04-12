#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define initialize(array,size,value) for(ll i=0;i<size;i++) array[i]=value
#define couta(array,size) for(ll i=0;i<size;i++) cout<<array[i]<<" "
#define debug(x) cout<<"x: "<<x<<endl
#define dbug(x,y) cout<<"x: "<<x<<"    "<<"y: "<<y<<endl
#define inf (long long int) 1e18
#define eps 0.000001
#define vl vector<ll> 
#define sl set<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll> 
#define pq priority_queue<ll>
#define mod 1000000007
#define MAXN 1000001
ll spf[MAXN]; 
ll gcd(ll a,ll b);
ll palindrome(string s);
ll modexp(ll a,ll b,ll m);
void sieve();
ll ceil(ll a, ll b);
vl getFactorization(ll x);
void getZarr(string str, ll Z[]);
vector<ll> prefix_function(string s);

vl adj[10005];
ll h[10005];
void dfs(ll s, ll e){
    for(auto x: adj[s]){
        if(x!=e){
            h[x]=h[s]+1;
            dfs(x,s);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   /* #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif*/

    ll n;
    cin>>n;
    ll a[n];
    loop(i,0,n) cin>>a[i];
    ll dp[n][n][2];
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            for(ll k=0; k<2; k++){
                dp[i][j][k]=0;
            }
        }
    }
    for(ll i=0; i<n; i++){
        dp[i][i][0]=a[i];
        dp[i][i][1]=-a[i];
    }
    for(ll i=1; i<=(n-1)*2; i++){
        if(i%2==1){
            ll x=(i+1)/2;
            for(ll j=0, k=x;k<n; j++, k++){
                dp[j][k][0]=max(a[j]+dp[j+1][k][1], a[k]+dp[j][k-1][1]);
            }
        }
        else {
            ll x=i/2;
            for(ll j=0, k=x; k<n; j++, k++){
                dp[j][k][1]=min(dp[j+1][k][0]-a[j], dp[j][k-1][0]-a[k]);
            }
        }
    }
    /*for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cout<<dp[i][j][0]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<n; j++){
            cout<<dp[i][j][1]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[0][n-1][0]<<endl;
}

ll gcd(ll a, ll b){
    if (a == 0)   return b;
    if(b==0)      return a;
    if (a == b)   return a;
    if (a > b)    return gcd(a%b, b);
    return gcd(a, b%a);
}

ll palindrome(string s){
    ll l = 0;
    ll h = s.length() - 1;
    while (h > l){
        if (s[l++] != s[h--]){
            return 0;
        }
    }
    return 1;
}

ll modexp(ll a, ll b, ll m){
    if (b==0)
        return 1;
    ll temp = modexp(a,b/2,m);
    temp = (temp*temp)%m;
    if (b&1)
        return (temp*(a%m))%m; // if b is odd a^b = a^(b/2)*a^(b/2)*a
    return temp;
}

void sieve() { 
    spf[1] = 1; 
    for (ll i=2; i<MAXN; i++) 
        spf[i] = i; 
    for (ll i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<MAXN; i++) { 
        if (spf[i] == i) { 
            for (ll j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 

vl getFactorization(ll x) 
{ 
    vl ret; 
    while (x != 1) 
    { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
} 

ll ceil(ll a,ll b){
    return a/b+(a%b!=0);
}

void getZarr(string str, ll Z[]){
    ll n = str.length();
    ll L, R, k;
    L = R = 0;
    for (ll i = 1; i < n; ++i){
        if (i > R){
            L = R = i;
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        } else {
            k = i-L;
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
            else {
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

vector<ll> prefix_function(string s) {
    ll n = (ll)s.length();
    vector<ll> pi(n);
    for (ll i = 1; i < n; i++) {
        ll j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}