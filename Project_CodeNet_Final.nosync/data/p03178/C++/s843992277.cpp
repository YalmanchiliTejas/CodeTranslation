#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll mod=1e9+7;
#define endl '\n'
#define SIGMA 128
const ld PI=3.14159265358979;
#define fr(i,n) for(ll i=1;i<=(n);i++)
#define rep(i,k,n) for(ll i=k;i<=(n);i++)
#define w(x) int x;cin>>x;while(x--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ps(x,y) cout<<fixed<<setprecision(y)<<x<<endl
#define pb push_back
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define vll vector<ll>
#define vvl vector<vll>
#define ppi pair<int,int>
#define ppl pair<ll,ll>
#define F first
#define S second 
#define LB lower_bound
#define UB upper_bound
#define mset multiset
#define uset unordered_set
#define umap unordered_map
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll binpow(ll x, ll y, ll p){  ll res = 1;x = x % p;if (x == 0)return 0;while (y > 0)  { if (y & 1) res = (res*x) % p; y = y>>1;x = (x*x) % p;}return res;}  
ll gcd(ll a, ll b){ if (b == 0) return a; return gcd(b, a % b); } 
bool parity(ll x,ll y){ bool f = ((x ^ y) < 0);return !f;}
string getBase(ll x,ll b){
    // returns number in reversed form
    //getBase(6,2) gives 011 AND NOT 110
    // make the sizes of returned strings equal before processing
    string ans;
    while(x){
        ans+=('0'+x%b);
        x/=b;
    }
    return ans;
}

string L,R;
ll d;
ll dp[10010][2][2][102];

ll cal(ll level,ll tlo,ll thi,ll rem)
{
    if(level>=R.size())
    {
        if(rem==0)
            return 1;
        return 0;
    }
    ll &ret=dp[level][tlo][thi][rem];
    if(ret!=-1)
        return ret;

    ret=0;

    ll diglo=0;
    ll dighi=9;
    if(tlo)
        diglo=L[level]-'0';
    if(thi)
        dighi=R[level]-'0';

    for(int i=diglo;i<=dighi;i++)
    {
        ll newlo=tlo;
        ll newhi=thi;
        if(i>L[level]-'0')
            newlo=0;
        if(i<R[level]-'0')
            newhi=0;
        
        ret+=cal(level+1,newlo,newhi,(rem+i)%d);
        ret%=mod;
    }
    return ret;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    IOS
    
    L="1";
    
    cin>>R;
    cin>>d;
    while (L.size()<R.size())
    {
        L+='0';
    }
    reverse(all(L));

    rep(i,0,10002)
        rep(j,0,1)
            rep(k,0,1)
                rep(kk,0,101)
                    dp[i][j][k][kk]=-1;

    cout<<cal(0,1,1,0)<<endl;
    

    return 0;  
}

