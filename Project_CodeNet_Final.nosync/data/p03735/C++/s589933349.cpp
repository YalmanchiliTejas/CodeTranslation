#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
//template end



int main(){
    int n; scanf("%d",&n);
    multiset<P> a; multiset<int> x,y;
    rep(i,0,n){
        int r,b; scanf("%d%d",&r,&b);
        if(r>b)swap(r,b);
        x.insert(r); y.insert(b);
        a.insert({r,b});
    }
    ll ans=INF;
    for(auto p:a){
        int r=p.first,b=p.second;
        chmin(ans,1LL*(*x.rbegin()-*x.begin())*(*y.rbegin()-*y.begin()));
        x.erase(x.find(r)); x.insert(b);
        y.erase(y.find(b)); y.insert(r);
    }
    printf("%lld\n",ans);
    return 0;
}