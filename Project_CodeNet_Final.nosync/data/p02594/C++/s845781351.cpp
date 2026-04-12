//Compiler optimization
#pragma GCC optimize("Ofast")

//include
#include <bits/stdc++.h>
using namespace std;

//typedef
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef string S;
typedef queue<int> qi;
typedef pair<ll,ll> P;
typedef vector<P> vp;
typedef vector<vl> mat;

//macro
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
#define unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define fr(i,n)for(ll i=0;i<(n);i++)
#define ifr(i,n)for(ll i=(n)-1;i>=0;i--)
#define all(x) x.begin(),x.end()

//abbreviation
#define pb push_back
#define elif else if
#define mp make_pair
#define endl '\n'

//debug
#define debug(x) cerr << #x << ': ' << x << endl

//const
const  ll INF = 1e18;

//どうせ使う
ll a,b,c,i,j,k,l,m,n,ans,tmp,hoge,fuga,piyo;

int main(){
    ll x; cin >> x;
    if(x>=30)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}