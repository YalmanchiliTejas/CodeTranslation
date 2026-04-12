#include<bits/stdc++.h>
/*
CE
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>

*/
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define mem(a,b) memset(a,b,sizeof (a))
#define ios std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
// ios  can not be used with scanf,printf.  IF  ios MUST cin,cout.
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;
const ll mod=998244353;
const int INF=0x3f3f3f3f;
ll ksm(ll a,ll b){ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

const int N=2e6+10;
ll n,x,m;
ll s[N],a[N];
ll ans;
map<ll,ll>vis;
int main(){
    scanf("%lld%lld%lld",&n,&x,&m);
    a[1]=s[1]=x;
    ll st=1,ed=n;
    for(ll i=2;i<=n;i++){
        a[i]=a[i-1]%m*a[i-1]%m;
        if(!vis[a[i]]){
            vis[a[i]]=i;
        }
        else{
            st=vis[a[i]];
            ed=i-1;
            break;
        }
        s[i]=s[i-1]+a[i];
    }
    ll c=n-(st-1);
    ll t=c/(ed-st+1),need=c%(ed-st+1);
    ans=s[st-1]+(s[ed]-s[st-1])*t+(s[st+need-1]-s[st-1]);
    printf("%lld \n",ans);
    return 0;
}
