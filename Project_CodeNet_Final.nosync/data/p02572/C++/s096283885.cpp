#include <bits/stdc++.h>
using namespace std;
#define rep(src,dst)    for(int i=src; i<dst;  i++)
#define rep2(src,dst)   for(int j=src; j<dst;  j++)
#define INF 1000000000000 //1e+12
#define MOD 1000000007 //1e9+7
#define PI  acos(-1)
#define ll long long
template<typename T> inline void cMin(T* a, T* b)  {if(*a>*b) *a=*b;}
template<typename T> inline void chMax(T* a, T* b) {if(*a<*b) *a=*b;}
template<typename T> inline int  div(T a, T b)     {return ((a+b-1)/b);}
template<typename T> inline bool eoVerify(T a)     {return (!(a&1)? true : false );}

int main(){
    ll n, ans=0, tmp=0;
    cin >> n;
    vector<ll> a(n);
    rep(0,n) cin >> a[i];

    rep(0,n){
        ans = (ans+a[i]*tmp)%MOD;
        tmp = (tmp+a[i])%MOD;
    }
    cout << ans << endl;
    return 0;
}
