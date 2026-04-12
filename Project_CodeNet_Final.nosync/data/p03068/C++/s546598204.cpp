#pragma GCC optimize ("O3")
#include <iostream>
#include <iomanip>
#include <istream>
#include <ostream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>
#define IINF 10e8
#define INF 1<<30
#define MOD 1000000007
#define mod 1000000007
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define Endl endl
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mmax(x,y)(x>y?x:y)
#define mmin(x,y)(x<y?x:y)
#define chmax(x,y) x=mmax(x,y)
#define chmin(x,y) x=mmin(x,y)
#define all(x) (x).begin(),(x).end()
#define siz(x) (ll)(x).size()
#define PI acos(-1.0)
using namespace std;
//using Int=int_fast64_t;
typedef long long int ll;
typedef long long int LL;
typedef pair<ll,ll>Pll;
typedef pair<int,int>Pin;
template<class T> using V=vector<T>;
long long GCD(long long a, long long b) { return b ? GCD(b, a%b) : a; }
long long LCM(long long a, long long b)  {return a/GCD(a,b)*b;}
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int ddx[8]={-1,0,1,0,1,1,-1,-1};
int ddy[8]={0,-1,0,1,1,-1,1,-1};
char dir[4]={'u','l','d','r'};
ll cmp(pair<ll,ll>a,pair<ll,ll> b){
        if(a.se!=b.se)
        return a.se<b.se;
        else
        return a.fi<b.fi;
}
//---------------------------------------------------------------------------
bool color[200001];
//---------------------------------------------------------------------------
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    //-------------------------------
    int n,k;string s;
    cin>>n>>s>>k;
    for(int i=0;i<n;i++)
        if(s[i]!=s[k-1])s[i]='*';
    cout<<s<<endl;
    //-------------------------------
    return 0;
}
//---------------------------------------------------------------------------

/*
ll n;cin>>n;
vector<ll>a(n);
for(ll i=0;i<n;i++)
    cin>>a[i];
 
ll n;cin>>s;
string s;cin>>s;

ll n,m;cin>>n>>m;
vector<ll>a(n),b(m);
for(ll i=0;i<n;i++){
    cin>>a[i];
}
for(ll i=0;i<m;i++){
    cin>>b[i];
}

ll n;cin>>n;
vector<Pll>xy;
for(ll i=0;i<n;i++){
    ll x,y;cin>>x>>y;
    xy.pb({x,y});
}
*/
