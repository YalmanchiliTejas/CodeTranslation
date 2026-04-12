/*
    BY - master_coder ( Tanu kumar )
    college - AIT
    Problem - contest ( div 3 )
*/
#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll  long long
#define PB push_back
#define ld long double
#define ff first
#define ss second
# define st(v) (v).begin(),(v).end()
#define rep(i,a,n) for( int i = a ; i < n ; i++ )
#define prep( i, a , n ) for ( int i = a ; i>= n ; i--)
#define   pr pair<int,int>
const int N = 1e5 + 5 , M=N,inf=(int)1e9;
const int mod=1e9+7;
int fastAbs(int n) { return (n ^ (n >> 31)) - (n >> 31); }
ll multiply(ll a, ll b){ return ((a % mod) * (b % mod)) % mod; }
ll add(ll a, ll b) {     return ((a % mod) + (b % mod)) % mod; }
ll sub(ll a, ll b) { return ((a%mod) - (b % mod)+ mod) % mod ; }
ll ans ;
map< pair<int,int> , int > mp;
const int dx[4] = {1,0,0,-1};
const int dy[4] = {0,-1,1,0};
vector < int > h[N];
void solve(){

   int x ;
   cin >> x ;
   if( x == 7 || x == 5 || x == 3) cout <<"YES";
   else cout << "NO";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q=1;
    //cin >> q;
    while(q--)
        solve();
}
/*
    ---------------- lemmas-----------------------------------
   1)
   2)
   3)

*/
