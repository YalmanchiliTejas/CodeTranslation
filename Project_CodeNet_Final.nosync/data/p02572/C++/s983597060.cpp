#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;
 
#define ll long long
#define ld long double
#define pb push_back
#define pr pair<ll, ll>
#define prf pair<ld,ld>
#define vct vector<ll>
#define vpt vector<pr>
#define vcf vector<ld>
#define vpf vector<prf>
#define st set<ll>
#define pq priority_queue<ll>
#define mat vector<vector<ll> >
#define all(x) x.begin(),x.end()
#define F(i, n) for(i = 0; i < (1LL*n); i++)
#define Fr(i, n) for(i = n - 1; i >= 0; i--)
 
struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define umap unordered_map<long long, long long, custom_hash>
 
void prv(vct v){for (ll i=0;i<v.size();i++)cout<<v[i]<<" ";cout << "\n";}
void prn(ll n){cout<<n<<"\n";}
void prs(string n){cout<<n<<"\n";}
void deb(string s, ll n){cout<<s<<" : "<<n<<"\n";}
void prmt(mat m){for(ll i=0;i<(1LL*m.size());i++)prv(m[i]);}
 
mat getRzMat(ll m,ll n, ll ini=0){mat mt;mt.assign(m,vector<ll>(n,ini));return mt;}
 
ll poww(ll x, ll y, ll m){
    ll res = 1;
    while (y){
        if (y%2 == 0){x = (x * x) % m;y = y / 2;}
        else{res = (res * x) % m;y--;}
    }
    return res;
}
 
vct divsors(ll n){
    vct ans;//ans.push_back(1);
    for(ll i=1;i<=sqrt(n);i++){if(n%i==0){ans.push_back(i);if(i!=(n/i))ans.push_back(n/i);}}
    sort(ans.begin(),ans.end());
    return ans;
}
vct sieve(ll n){
    vct ans(n+1,-1);
    for(ll i=2;i<=n;i++){
        if(ans[i]==-1){
            for(ll j=i;j<=n;j+=i)if(ans[j]==-1)ans[j]=i;
        }
    }
    return ans;
}
mat mt;
ll n, k, m, l, r, x, y, z, ans=0;
ll t, t1, t2;
ll q;
ll i, j;
ll a, b, c, d, w;
ll mod = 1000000007;
ld epi = 0.00000001;
ll cas=0;
void solve(){
    
    cin>>n;
    ans=0;
    vct v(n,0);
    F(i,n)cin>>v[i];

    ll su=0;
    F(i,n)su+=v[i];

    su=su%mod;
    // prn(su);
    F(i,n){
        su-=v[i];
        if(su<0)su+=mod;
        ans=(ans+((v[i]*su)%mod))%mod;
    }
    prn(ans);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cout<<fixed<<setprecision(10);
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    ll t = 1;
    // cin >> t;
    cas=1;
    while (t--){
        solve();
        cas++;
    }
    return 0;
}
 
