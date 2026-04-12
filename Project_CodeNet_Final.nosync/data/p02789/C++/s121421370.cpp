#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define ldb long double 
#define db double
#define str string

#define fr first
#define se second
#define lb lower_bound 
#define ub upper_bound 
#define pb push_back
#define mpr make_pair

#define pi pair<int,int>
#define pll pair<ll,ll>
#define pdb pair<db,db>
#define pldb pair<ldb,ldb>

#define vi vector<int>
#define vll vector<ll>
#define vdb vector<db>
#define vldb vector<ldb>
#define vpi vector< pi >
#define vpll vector< pll >

#define mi map<int,int>
#define mll map<ll,ll>
#define mdb map<db,db>
#define mldb map<ldb,ldb>


#define forr(a,b) for (int i = (a); i < (b); ++i)
#define rrof(a,b) for (int i = (b)-1; i >= (a); --i)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int md = 1e9+7;
const int MX = 2e5+5;
const ll INF = 1e18; 
const ldb PI = 4*atan((ldb)1);

ll power(ll a,ll n)
{
 ll res=1;
 while(n)
{
 if(n%2)
  res*=a;
  a*=a;
  n/=2;
}
return res;
}

ll abst(ll a)
{
 return ((a<0)?(-1*a):(a));
}

int main()
{
    int n,m;
    cin>>n>>m;
    if(n==m)
     cout<<"Yes\n";
     else
      cout<<"No\n";
      return 0;
    
}