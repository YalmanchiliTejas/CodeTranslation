#include<bits/stdc++.h>
using namespace std;
 
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MP make_pair
#define pb push_back
#define ff first
#define ss second
#define sz(x) x.size()
#define all(c) c.begin(),c.end()
#define int long long
#define fr(i,j,x) for(int i=j;i<x;i++)
#define rep(i,j,x) for(int i=j;i<=x;i++)
#define mem(x,val) memset(x,val,sizeof(x))
//#define endl '\n'
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<int,pii>
 
const int mod=1e9+7;
const int N=2e5+10;
const int MAXN=2e6+10;
const int INF=1e18;

string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

int a[N];

int power(int x, int y, int p)  {  
    int res = 1; 
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res;  
} 

int Inv(int a, int m) { 
    return power(a, m-2, m); 

} 
  
void solve(){
    int n;
    cin>>n;
    int sum=0,sq=0;
    rep(i,1,n){
        int a;
        cin>>a;
        sum+=a;
        sum%=mod;
        sq+=a*a;
        sq%=mod;
    }
    int ans=((sum*sum)%mod-sq+mod)%mod;
    ans=(ans+mod)%mod;
    ans*=Inv(2,mod);
    ans%=mod;
    cout<<ans<<endl;
}


int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("inputf.in", "r", stdin);
    //     //freopen("outputf.in", "w", stdout);
    // #endif
    SPEED;
    int T=1;
    //cin>>T;
    int t1=1;
    while(true)
    {  
        //cout<<"Case #"<<t1<<": ";
        solve();
        t1++;
        if(t1>T)
            break;
    }
}