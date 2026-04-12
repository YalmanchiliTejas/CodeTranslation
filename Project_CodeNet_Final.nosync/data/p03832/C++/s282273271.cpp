#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "E"
const ll base=1000000007;
ll f[1001][1001];
ll h[1001][1001];
ll nt[1001][1001];
ll fact[1001];
bool done[1001][1001];
bool doneh[1001][1001];
ll F(int, int);
ll power(ll a, int x){
    if(x==0) return 1;
    ll t=power(a, x/2);
    t=(t*t)%base;
    if(x%2) t=(t*a)%base;
    return t;
}
int n, a, b, c, d;
ll H(int u, int v){
    if(doneh[u][v]) return h[u][v];
    doneh[u][v]=1;
    return h[u][v]=(fact[u*v]*power((fact[v]*power(fact[u], v))%base, base-2))%base;
}
//ll G(int u, int v){
//    if(u<0) return 0;
//    if(doneg[u][v]) return g[u][v];
//    doneg[u][v]=1;
//    return g[u][v]=(F(u, v)+G(u-v-1, v))%base;
//}
ll F(int u, int v){
//    write(u);
//    putchar(' ');
//    write(v);
    if(done[u][v]) return f[u][v];
    done[u][v]=1;
    if(u==0) return f[u][v]=1;
    if(v<a) return f[u][v]=0;
    f[u][v]=F(u, v-1);
    FOR(i, c, d) if(i*v<=u) f[u][v]=((F(u-i*v, v-1)*((nt[u][i*v]*H(v, i))%base))%base+f[u][v])%base;
    else break;
    f[u][v]%=base;
    return f[u][v];
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    fact[0]=1;
    FOR(i, 1, 1000) fact[i]=(fact[i-1]*i)%base;
    nt[0][0]=1;
    FOR(i, 1, 1000){
        nt[i][0]=nt[i][i]=1;
        FFOR(j, 1, i) nt[i][j]=(nt[i-1][j]+nt[i-1][j-1])%base;
    }
    read(n);
    read(a);
    read(b);
    read(c);
    read(d);
    writeln(F(n, b));
    FOR(i, 1, n) FOR(j, 1, n) if(f[i][j]<0) bug(f[i][j]);
}