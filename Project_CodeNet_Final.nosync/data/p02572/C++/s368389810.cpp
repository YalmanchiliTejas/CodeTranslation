
#include<bits/stdc++.h>
#include<queue>
using namespace std;

#define what_is(x) cout << #x << " is " << x << endl;
#define PI acos(-1)
#define hell 1000000007
#define HELL 998244353
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fix(n) cout << fixed << setprecision(n)
#define mset(a,n) memset(a,n,sizeof a)
#define rep(i,a,b) for (__typeof((b)) i=(a);i<(b);i++)
#define repp(i,a,b,p) for(__typeof((b)) i=(a);i<(b);i+=p)
#define ren(i,a,b) for(__typeof((a)) i=(a);i>=(b);i--)
#define renn(i,a,b,p) for(__typeof((a) i=(a);i>=(b);i-=p)
#define ADD(a,b,c) ((a)%c+(b)%c)%c
#define SUB(a,b,c) ((a)%c-(b)%c+c)%c
#define MUL(a,b,c) (((a)%c)*((b)%c))%c
#define lbd lower_bound
#define ubd upper_bound
#define ll long long
#define ld long double
#define pb push_back
#define fi first
#define se second
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define all(v) (v).begin(), (v).end()
#define sz(x) (ll)x.size()
// #define out(n) cout<<n<<" "
#define outl(n) cout<<n<<endl
#define bug(n) {outl(n);return;}
#define pii pair<int,int>
#define lim 9223372036854775805
#define ninf -9223372036854775802
#define M 1000000007
#define eps 1e-9
#define MAX 10
#define N 500001
#define db(a) for(auto it:a) {cout<<it<<" ";}cout<<endl;
ll prime[MAX];
ll fact[MAX];

const long long INF64 = 1e18;
ll vpow(ll a,ll b,ll p){
    if(b==0)
        return 1;
    if(b==1)
            return a;
    ll temp=vpow(a,b/2,p);
    temp*=temp;
    temp%=p;
    if(b%2==0)
        return temp;
    temp=temp*a;
    temp%=p;
    return temp;
}

ll gcd(ll a,ll b){
     if(a==0)
         return b;
     return gcd(b%a,a);
 }


ll inverseMod(ll a,ll b,ll p){
    if(b==0)
        return 1;
    ll temp=vpow(b,p-2,p);
    ll ans=temp*a;
    ans%=p;
    return ans;
}
void sieve()
{
    prime[0] = prime[1] = 1;
    for (ll i = 2; i < MAX; i++) {
        if (prime[i] == 0) {
            for (int j = i * 2; j < MAX; j += i) {
                if (prime[j] == 0) {
                    prime[j] = i;
                }
            }
            prime[i] = i;
        }
    }
}
ll max(ll a, ll b)
{
    return a>b?a:b;
}

void factorial(){
    fact[0]=1;
    fact[1]=1;
    rep(i,2,MAX){
        fact[i]=(fact[i-1]*i);
        // fact[i]%=M;
    }
}
ll rand(ll a,ll b){
    return a+rand()%(b-a+1);
}

void solve(ll ttt){
    ll n;
    cin>>n;
    ll a[n],pre[n];
    ll i,sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    pre[n-1]=a[n-1];
    ll ans=0;
    for(i=n-2;i>-1;i--)
    {
        pre[i]=(pre[i+1]+a[i])%M;
    }
    for(i=0;i<n-1;i++)
    {
        ans=ans+((a[i]*pre[i+1])%M);
        ans=ans%M;
    }
    cout<<ans<<endl;
    return;

}

int main(){
    io;
    // sieve();
    // factorial();
#ifndef ONLINE_JUDGE
    //
    //freopen("input1.txt","r",stdin);
    // freopen("output1.txt","w",stdout);
#endif
    ll t=1;
     //cin>>t;
    fix(12);
    rep(q,1,t+1){
         //cout<<"Case #"<<q<<": ";
         solve(q);
    }
    return 0;

}


