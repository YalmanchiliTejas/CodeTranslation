#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define bg begin()
#define en end()
#define pb push_back
#define w(x) scanf("%d",&x);while(x--)
#define ws(x) scanf("%d",&x);getchar();while(x--)
#define rep(i,b) for(i=0;i<=b;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 2*acos(0.0)
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int N=1e6+2;
long long  mod=1e9+7;
int t,j,cs=0,n,a,b,i,dxx[]={1,0,0,-1},dyy[]={0,-1,1,0},k,m;
string s;

int main()
{
cin>>n;
    ll ar[n+1],sum[n+1]={};
    rep(i,n-1) cin>>ar[i];
    for(i=n-1;i>=0;i--)
        sum[i]=sum[i+1]+ar[i];

    ll cnt=0;
    for(i=0;i<n;i++){
        ar[i]%=mod;
        sum[i+1]%=mod;
        cnt+=(ar[i]*sum[i+1])%mod;
        cnt%=mod;
    }
    cout<<cnt<<endl;
}

