#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<queue>
#include<math.h>
#include<ctime>
#include<deque>
#include<set>
#include<string.h>
#include<algorithm>
#include<map>
#include<stack>
#define ll long long
#define ld long double
#define ull unsigned long long
#define ls rt<<1
#define rs rt<<1|1
#define mmm(a,b) memset(a,b,sizeof(a))
#define sc(x) scanf("%d",&x)
using namespace std;
const ll mod = 1e9+7;
const ll inf = 1e17;
const double pi = acos(-1.0);
const int maxn = 1e6+5;
ll kase;
ll n,m,p;
ll f[maxn],vis[maxn];
map<ll,int>st;
void run(){
    ll tmp;
    cin>>n>>m>>p;
    ll ans=0;
    if(n<(ll)maxn){
        for(int i=0;i<n;i++){
            if(m==0)break;
            ans+=m;
            m=m*m%p;
        }
        cout<<ans<<'\n';
    }
    else {
        ll len=0,s;
        tmp=m;
        for(ll i=0;i<n;i++){
            if(m==0){
                cout<<ans<<'\n';
                return;
            }
            if(st.count(m)){
                s=st[m];
                len=i-s;
                break;
            }
            st[m]=i;
            ans+=m;
            m=m*m%p;
        }
        ll tans=0;
        for(int i=0;i<s;i++){
            tans+=tmp;
            tmp=tmp*tmp%p;
        }
        ans-=tans;
        n-=s;
        ans*=(n/len);
        n%=len;
        ans+=tans;
        for(int i=0;i<n;i++){
            ans+=m;
            m=m*m%p;
        }
        cout<<ans;
    }
}
int main(){
#ifdef haosao
freopen("main.h", "r", stdin);
//freopen("out.txt","w",stdout);
#endif
    ios::sync_with_stdio(false);
//    cin>>kase;
//    while(kase--)
        run();
    return 0;
}
