//*******************************************************ランダムなもの***********************************************************************
// double num1 = 3.12345678; cout << fixed << showpoint; cout << setprecision(9); cout << num1 << endl; printf("%0.9lf \n", side); for double
// struct foo{ int a,b,c; }; typedef struct foo foo;
// typedef pair<int, int> pi; 
// struct Compare{ bool operator()(pi const & a, pi const & b){ if(a.first==b.first){ return a.second>b.second; } return a.first<b.first; } };
// priority_queue<pi , vector<pi>, Compare> pq; priority_queue <int, vector<int>, greater<int> > pq; # Min Heap
// for(ll i=1;i<=m+1;i++) f[i]=(f[i-1]%mod * i%mod)%mod; mcn = (f[m]%mod * power(f[n],mod-2,mod)%mod * power(f[m-n],mod-2,mod)%mod)%mod;
// void bfs(int i){ queue<pair<int,int>> q; q.push(mp(i,0)); vis[i]=1;
// while(!q.empty()) { pair<int,int> temp=q.front(); q.pop(); d[i][temp.first]=temp.second;
// for(auto it=g[temp.first].begin();it!=g[temp.first].end();it++) {if(vis[*it]==0){vis[*it]=1; q.push(mp(*it,(temp.second)+1));}}}}
// void dfs(int child,int parent,vector<int> &d,vector<int> &p,int &tx,vector<int> &tin,vector<int> &tout) { tin[child]=tx++;
// for(auto it = g[child].begin();it!=g[child].end();it++) { if(*it==parent) continue;
// d[*it]=1+d[child]; p[*it]=child; dfs(*it,child,d,p,tx,tin,tout);} tout[child]=tx++; }
//**********************************************************数や******************************************************************************
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define endl '\n'
#define PI 3.14159265
#define ff first
#define ss second
#define tab '\t'
#define deb cout<<"error"<<endl
#define uset unordered_set
#define mset multiset
#define umap unordered_map
#define mmap multimap
#define len length
#define SZ(x) (int)(x).size()
#define nbits(d) (int)log2(d)+1
// struct chash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);}
// size_t operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// return splitmix64(x + FIXED_RANDOM);} };
ll gcd (ll a, ll b){ if(b==0) return a; else return gcd(b,a%b); }
ll power(ll a, ll n){ ll res=1; while(n!=0) { if(n%2){ res=res*a; n--; } else { a=a*a; n=n/2; } } return res;}
ll powermod(ll a, ll n, ll m){ ll res=1; while(n!=0) { if(n%2){ res=(res%m*a%m)%m; n--; } else { a=(a%m*a%m)%m; n=n/2; } } return res%m;}
/*Any INT overflow ? Inside while loop < n, okay ? ! Multiple GRAPHS in testcases ? Reinitialize global ! End cases n=0 || n=1 ?
*Do and write something insted of nothin okay?! * これらのコードの作成者 - ビベックシャルマ */

void jiejue() 
{   
    int n;
    cin>>n;
    if(n>=30) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

signed main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); int teseuteu;
teseuteu=1; while(teseuteu--) jiejue();
// cin>>teseuteu; while(teseuteu--) jiejue();
}
