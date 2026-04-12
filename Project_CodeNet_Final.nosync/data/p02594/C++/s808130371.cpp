#include<bits/stdc++.h>
#include<cstring>
#include<cmath>
#include<iterator>
#include<cstdlib>
#define IOS   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ses   "\n"
#define whp   " "
#define mxi 99999
#define mp make_pair
#define PII pair<int, int>
#define pf printf
#define sf scanf
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define PI acos(-1)
#define sz(a) long long(a.size())
#define ff first
#define ss second
#define forch(it,s) for(auto it:s)
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define rep0(i,a,b) for(int i=a; i<b; i++)
#define rep1(i,a,b) for(int i=a; i<=b; i++)
#define rep0in(i,a,b) for(int i=a-1; i>=b; i--)
#define rep1in(i,a,b) for(int i=a; i>b; i--)
#define repv(i,a) for(auto i=a.begin(); i!=a.end();++i)

///priority_queue <int, vector<int>, greater<int>> g
#define MS(a,b) memset(a,b,sizeof(a));

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll fx[4]= {1,-1,0,0};
ll fy[4]= {0,0,1,-1};

typedef vector<ll> vll;
typedef vector<string> vss;
typedef vector<pair<ll,ll > > vpr;
typedef vector<pair<string,ll > > vspr;
typedef list<ll> li;
typedef list<string> ls;
typedef list<pair<ll,ll> > lpr;
typedef list<pair<string,ll> > lspr;

bool rs(ll a, ll b){return(a>b);}
ll spd(ll n){ if(n%2==0)return 2; for(ll i=3; i*i<=n; i++){if(n%i==0)return i;}return n;}

int main(){
ll n; cin>>n;
if(n>=30){cout<<"Yes"<<endl;}
else cout<<"No"<<endl;


return 0;
}
