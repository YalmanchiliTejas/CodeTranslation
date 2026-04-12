/// --- In the name of ALLAH --- ///


//#include <cmath>
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;


typedef long long              ll;
typedef vector<int>            vi;
typedef vector<ll>             vl;
typedef vector<vi>             vvi;
typedef vector<vl>             vvl;
typedef pair<int,int>          pii;
typedef pair<double, double>   pdd;
typedef pair<ll, ll>           pll;
typedef vector<pii>            vii;
typedef vector<pll>            vll;
typedef double                 dl;

#define endl                   '\n'
#define PB                     push_back
#define F                      first
#define S                      second
#define all(a)                 (a).begin(),(a).end()
#define rall(a)                (a).rbegin(),(a).rend()
#define sz(x)                  (ll)x.size()
#define wt                     ll t; cin>>t; while(t--)
#define input(a,n)             for(int i=0;i<n;i++) cin>>a[i];

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;


#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))
#define mod 10000007
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


const ll mx=1e9;




int main()
{
    optimize();
int n,i,c=1,j,q=0;
cin>>n;
int h[n+1];
for(i=1;i<=n;i++)
{
    q=0;
    cin>>h[i];
    if(i==1)
        continue;
    for(j=1;j<i;j++)
    {
        if(h[j]<=h[i])
            q++;
    }
    if(q==i-1)
            c++;

}
cout<<c<<endl;
    return 0;
}




























































































