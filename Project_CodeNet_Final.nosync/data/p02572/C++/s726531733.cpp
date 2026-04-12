#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    ll sum=0;
    rep(i,1,n) sum+=a[i];
    sum%=mod;
    sum=1ll*sum*sum%mod;
    rep(i,1,n) sum=(sum-1ll*a[i]*a[i])%mod;
    sum=(sum+mod)%mod;
    sum=1ll*(mod+1)/2*sum%mod;
    printf("%lld\n",sum);
    return 0;
}
