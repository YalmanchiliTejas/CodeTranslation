#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
template<class T> inline bool chmax(T& a, T b){ if(a<b){a=b;return 1;}return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){a=b;return 1;}return 0; }
//template end



int main(){
    int n; scanf("%d",&n);
    vector<int> a(n);
    rep(i,0,n)scanf("%d",&a[i]);
    ll ans=0;
    rep(p,1,n){
        ll sub=0; int lb=0,rb=n-1;
        if((n-1)%p==0){
            while(lb<rb){
                sub+=a[lb]+a[rb];
                chmax(ans,sub);
                lb+=p; rb-=p;
            }
        }
        else{
            while(lb<n-1-p){
                sub+=a[lb]+a[rb];
                chmax(ans,sub);
                lb+=p; rb-=p;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}