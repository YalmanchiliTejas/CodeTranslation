#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <sstream>
#include <string>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=100001;
bool vis[N];
vector <int> adj[N];
ll gcd(ll a, ll b) { if (a == 0) return b; return gcd(b % a, a); } 
ll lcm(ll a, ll b){return a*b/gcd(a, b);}
ll binaryNum[32];
void decToBinary(ll n) 
{ 
    binaryNum[32]={0};
    int i = 0; 
    while (n > 0) { 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
} 

void solve(){
    ll x;
    cin>>x;
    if(x>=30){
        cout<<"Yes";
    }
    else cout<<"No";


}


int main()
{
    // cout<<1<<endl;
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
    
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    // cin>>T;
    int t=0;
    while(t++<T)
    {
        // cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}