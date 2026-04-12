#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
template <typename CT, typename T> inline void reset_container(CT &c, int sz, T v){c.resize(sz); for(auto &x: c) x=v;}
#define taskname "agc026_d"
int n;
int h[101];
const ll base=1000000007;
ll power(ll a, ll b){
    if(b==0) return 1;
    ll t=power(a, b/2);
    t=(t*t)%base;
    if(b%2) t=(t*a)%base;
    return t;
}
int minpos[101][101];
bool doneg[101][101][101];
ll g[101][101][101];
ll G(int l, int r, int low){
    if(l>r) return 1;
    ///calculate from l to r, above low
    if(doneg[l][r][low]) return g[l][r][low];
    doneg[l][r][low]=1;
    int x=minpos[l][r];
    return g[l][r][low]=((G(l, x-1, (h[x]>h[low])?x:low)*G(x+1, r, (h[x]>h[low])?x:low))%base*power(2, max(0, h[x]-h[low])))%base;
}
bool done[101][101];
ll f[101][101];
ll F(int l, int low){
    if(done[l][low]) return f[l][low];
    done[l][low]=1;
    int aff[101];
    aff[l]=low;
    FOR(i, l+1, n) aff[i]=(h[i]<h[aff[i-1]])?i:aff[i-1];
    FOR(i, l+1, n){
        int aff2[101];
        ll cnt=1;
        FOR(x, l, i) aff2[x]=aff[x];
        int now=i;
        DFOR(j, i, l){
            if(h[j]<h[now]) now=j;
            if(h[aff2[j]]<h[now]) aff2[j]=now;
        }
        FOR(j, l, i){
            int k=j;
            while((k<i-1)&&(aff2[k+1]==aff2[j])) k++;
            cnt=(cnt*G(j, k, aff2[j]))%base;
            j=k;
        }
        if(h[i]>h[i-1]){
            f[l][low]+=(cnt*F(i, i-1))%base;
        }
        else{
            f[l][low]+=(cnt*F(i, i))%base;
        }
    }
    ll cnt=1;
    FOR(j, l, n){
        int k=j;
        while((k<n)&&(aff[k+1]==aff[j])) k++;
        cnt=(cnt*G(j, k, aff[j]))%base;
        j=k;
    }
    f[l][low]+=cnt;
    f[l][low]%=base;
    return f[l][low];
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    FOR(i, 1, n) read(h[i]);
    FOR(l, 1, n) FOR(r, l, n) minpos[l][r]=min_element(h+l, h+r+1)-h;
    h[0]=1;
    writeln((F(1, 0)*2)%base);
}