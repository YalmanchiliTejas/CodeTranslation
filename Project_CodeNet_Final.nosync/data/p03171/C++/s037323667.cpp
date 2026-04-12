#include <bits/stdc++.h>

using namespace std;

#define ops cout<<"ops"<<endl;
#define freopens freopen("cowpatibility.in", "r", stdin);freopen("cowpatibility.out", "w", stdout);
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define DIM 3007
#define DIMM 100007
#define INF 1000000000007.0
#define X (ll)(1<<32)
#define eps 0.0000001
#define PI 3.14159265358979323846
#define MAX 25
#define MODULO (long long)1000000007

const long double gr=(1+sqrt(5))/2;

typedef int I;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef pair<I,I> pII;
typedef pair<ll,ll> pllll;
typedef pair<ld,ld> pldld;

typedef vector<I> vI;
typedef vector<ll> vll;
typedef vector<pllll> vpllll;

typedef char cr;
typedef string str;

ll n;
ll a[DIM],dp[DIM][DIM];

int main()
{
    //ops;
    //freopens;
    fast;
    //ll x1,y1,xs,ys,x2,y2,x3,x4,y3,y4;

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int l=1;l<=n;l++){
     for(int s=1;s<=(n-l+1);s++){
      dp[s][l]=max((a[s+l-1]-dp[s][l-1]),(a[s]-dp[s+1][l-1]));
     }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
