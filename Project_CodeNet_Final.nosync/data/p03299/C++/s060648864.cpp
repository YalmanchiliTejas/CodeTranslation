#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cmath>
#include<vector>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int maxn=1e5+100;
const int mod=1e9+7;
const int inf=1e9+1000;
int h[maxn],n;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
inline ll ksm(ll num,ll t) {
    ll res=1;num%=mod;
    for(;t;t>>=1,num=num*num%mod) {
        if(t&1)res=res*num%mod;
    }
    return res%mod;
}
pll solve(int l,int r,int c) {
    if(l>r)return mk(1,0);
    vi tmp;tmp.clear();int mi=inf,w=0;
    pll ans=mk(1,1);
    for(int i=l;i<=r;i++)mi=min(mi,h[i]);
    tmp.push_back(l-1);for(int i=l;i<=r;i++)if(h[i]==mi)tmp.push_back(i),w++;tmp.push_back(r+1);
    for(int i=1;i<tmp.size();i++) {
        int le=tmp[i-1]+1,re=tmp[i]-1;
        pll tmp_ans=solve(le,re,mi);
        ans.fi*=tmp_ans.fi;ans.fi%=mod;
        ans.se*=tmp_ans.fi+tmp_ans.se;ans.se%=mod;
    }
    ans.se=ans.se*ksm(2,w)%mod+(ksm(2,mi-c)-2)*ans.fi%mod;ans.se%=mod;
    ans.fi*=ksm(2,mi-c);ans.fi%=mod;
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    pll ans=solve(1,n,0);
    cout<<ans.se;
}