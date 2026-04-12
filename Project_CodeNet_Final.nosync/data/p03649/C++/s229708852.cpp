/*
Till the roof comes off, till the lights go out
Till my legs give out, can’t shut my mouth.
Till the smoke clears out. Am I high? Perhaps
I'ma rip this shit till my bones collapse.
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <stack>
#include <string.h>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#include <stack>
#include <complex>

#define pb push_back
#define f first
#define s second
#define ll long long
#define sz(v)      ((int)((v).size()))
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define len(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)

using namespace std;

typedef pair<int,ll>ii;
typedef pair<ii,int>node;
typedef complex<double>point;


const int N=1005;
const int M=101;
const double EPS = 1e-9;
const int INF =1e9;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
double getDist(point a,point b){return sqrt((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y));}
int dcmp(double x, double y) {return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;}

ll mod=1000000007;
ll power(ll base,int p){if(!p)return 1;ll ret=power(base,p/2);ret*=ret;ret%=mod;if(p&1)ret*=base,ret%=mod;return ret;}
ll modInverse(int a){return power(a,mod-2);}

vector<ll>v;
int n;
bool can(ll l){
 for(ll total=l;total>max(l-100,0ll);total--){
   ll sum=total;
   for(int i=0;i<n;i++){
        ll k = v[i] - n*1ll + total +n;
        k/=((n+1)*1ll);
        if(v[i]-k*n*1ll+total-k>=n)k++;
        sum-=k;
   }
   if(sum>=0)return 1;
 }return 0;
}
int main()
{
    //freopen("test.in","r",stdin);
    // freopen("test.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        v.pb(a);
    }
    sort(v.begin(),v.end());
    if(v[n-1]<n){
        cout<<0;
        return 0;
    }
    reverse(v.begin(),v.end());
    ll low=0,high=1e18;
    while(low+1<high){
        ll mid=(low+high)/2;
        if(can(mid))
            high=mid;
        else
            low=mid+1;
    }
    if(can(low))cout<<low;
    else cout<<high;
  return 0;
}

/*
100% reason to Remember THE NAME
*/
