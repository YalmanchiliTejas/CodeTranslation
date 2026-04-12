#include<bits/stdc++.h>
#define MEM(dp,i) memset(dp,i,sizeof(dp))
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int MX=5000;
const ll inf=(1ll<<60);
const ll mod=1e9+7;
ll n,sum,k,ans;
int main(){
    scanf("%lld",&n);
    sum=n*800;
    n/=15;
    k+=n*200;
    printf("%lld\n",sum-k);
}
