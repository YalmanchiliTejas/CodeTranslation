#pragma GCC optimize(2)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int maxn = 1e6+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;
const ll inf2 = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9+7;
inline void read(int &x){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    x = s*w;
}

int N;
int a[maxn];
ll ksm(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    ll ans = 0,sum = 0,sum2 = 0;
    for(int i =1;i<=N;i++) sum = (sum + a[i])%mod;
    for(int i = 1;i<=N;i++) sum2 = (sum2 + (ll)a[i]*a[i])%mod;
    ans = (sum*sum%mod - sum2 + mod) %mod *ksm(2,mod-2)%mod;
    cout<<ans<<'\n';
}
int main(){
//    debug;
    ios;

    cin>>N;
    for(int i =1;i<=N;i++) cin>>a[i];
    solve();


    return 0;
}