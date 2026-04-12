#pragma GCC optimize("Ofast")   //Comment optimisations for an interative problem/use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;  
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss;  
typedef vector<pll> vpll; 
typedef vector<ll> vll; 
typedef vector<vll> vvll; 
typedef unordered_map<ll,ll> um;

#define fastio ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define sqr(x) ((ll)(x) * (x)) 
#define reset(a, b) memset(a, b, sizeof(a)) 
#define f first 
#define s second 
#define mp make_pair 
#define pb push_back 
#define all(v) v.begin(), v.end() 
#define alla(arr, sz) arr, arr + sz 
#define showv(v) for(auto it: (v))cout<<it<<" ";newl;
#define newl cout<<"\n"

const ll MAXN=1e+2+7;
const ll MOD=1e+9+7, INF=0x7f7f7f7f7f7f7f7f;const int INFi=0x7f7f7f7f;
double EPS = 1e-9;  
double PI = acos(-1); 

vll adj[MAXN];ll visit[MAXN]={};
int dx8[]={0,1,1,1,0,-1,-1,-1}, dy8[]={1,1,0,-1,-1,-1,0,1},dx4[]={0,1,0,-1}, dy4[]={1,0,-1,0};

//<<-----Declare Variable Here------->>//
ll t,n;
ll i,j;
 
//<<-----Implement Functions Here---->>//
 
 
//<<-----Start of Main--------------->>//

int main()
{

	

	cin >> n >> t;
	if(n==t)cout<<"Yes";
	else cout<<"No";
}