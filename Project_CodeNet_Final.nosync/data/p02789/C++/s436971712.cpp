// --------------------<optimizations>--------------------
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)
#pragma GCC optimize("unroll-loops")
// -------------------</optimizations>--------------------
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define f first
#define s second
#define sz(x) int(x.size())
#define endl '\n'
#define forn(i,n) for(int i=0;i<n;++i)
#define fore(i,l,r) for(int i=int(l);i<=int(r);++i)
#define rep(i,begin,end) for(__typeof(end) i=(begin);i!=(end);i++)
#define fill(a,value) memset(a,value,sizeof(a));
#define SIZE 26     
#define watch1(x) cout << (x) << endl
#define watch2(x,y) cout << (x) << " " << (y) << endl
#define watch3(x,y,z) cout << (x) << " " << (y) << " " << (z) << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
 
typedef long long ll;
typedef long double ld; 
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
 
const ll mod = 1e9 + 7;
const int inf = 1e9 + 5;
const int N = 1e5 + 5;
 
signed main(){
    fastio;
    int i,n,m;
    cin>>n>>m;
    if(m==n) cout<<"Yes";
    else cout<<"No";
    return 0;
}