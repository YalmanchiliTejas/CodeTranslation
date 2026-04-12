#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define per(a,b,c) for(int a=b;a>=c;a--)
#define ios; ios::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define ls(x) (x<<1)
#define rs(x) (ls(x)|1)
#define eps 1e-11
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef double db;
mt19937 rnd(random_device{}());
const int mod = 1e9 + 7;
const int N = 1e3 + 5;
const int M = 1e3 + 5;
inline ll gcd(ll a,ll b){ return b?gcd(b,a%b):a; }
inline ll lcm(ll a,ll b){ return a*b/gcd(a,b); }
inline ll ksm(ll x,ll y){ ll res=1; while(y){if(y&1) res=res*x%mod;
x=x*x%mod; y>>=1;} return res; }
int n,m,k;

int main(){
    cin>>n;
    if(n>=30) cout<<"Yes\n";
    else cout<<"No\n";
    //scanf("%d",&n);
    //printf("%s\n",n>=30?"Yes":"No");
    return 0;
}