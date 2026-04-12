#include<bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll  long long
#define PB push_back
#define ld long double
#define ff first
#define ss second
# define st(v) (v).begin(),(v).end()
#define   pr pair<int,int>
using namespace std::chrono;
const int N = 1e5+4 , M=N,inf=(int)1e9;
const ll mod=1e9+7;
int fastAbs(int n) { return (n ^ (n >> 31)) - (n >> 31); }
ll multiply(ll a, ll b){ return ((a % mod) * (b % mod)) % mod; }
ll add(ll a, ll b) {     return ((a % mod) + (b % mod)) % mod; }
ll sub(ll a, ll b) { return ((a%mod) - (b % mod)+ mod) % mod ; }
int ans ;
map< pair<int,int> , int > mp;
const int dx[4] = {1,0,0,-1};
const int dy[4] = {0,-1,1,0};
void solve(){
    int n ;
    cin >> n ;
    string s;
    cin >> s;
    int k ;
    cin >> k ;
    k--;
    char c = s[k];
    for( int i = 0 ; i < n ; i++){
        if(s[i]!=c){
            cout <<"*";
        }
        else cout << s[k];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q=1;
   // cin >> q;
    while(q--)
        solve();
}
