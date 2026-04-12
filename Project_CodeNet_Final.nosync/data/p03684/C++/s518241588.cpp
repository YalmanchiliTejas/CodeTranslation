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
#define taskname "D"
int n;
struct town{
    int x, y;
    int i;
} t[100001];
bool cmpx(town a, town b){
    return a.x<b.x;
}
bool cmpy(town a, town b){
    return a.y<b.y;
}
struct edge{
    int u, v, c;
} e[200001];
bool cmp(edge a, edge b){
    return a.c<b.c;
}
int m;
int r[100001];
int root(int u){
    if(r[u]<0) return u;
    return r[u]=root(r[u]);
}
bool uni(int u, int v){
    u=root(u); v=root(v);
    if(u!=v){
        if(r[u]>r[v]) swap(u, v);
        r[u]+=r[v];
        r[v]=u;
        return 1;
    }
    return 0;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n){
        read(t[i].x);
        read(t[i].y);
        t[i].i=i;
    }
    sort(t+1, t+n+1, cmpx);
    FOR(i, 2, n){
        m++;
        e[m].u=t[i].i;
        e[m].v=t[i-1].i;
        e[m].c=t[i].x-t[i-1].x;
    }
    sort(t+1, t+n+1, cmpy);
    FOR(i, 2, n){
        m++;
        e[m].u=t[i].i;
        e[m].v=t[i-1].i;
        e[m].c=t[i].y-t[i-1].y;
    }
    FOR(i, 1, n) r[i]=-1;
    sort(e+1, e+m+1, cmp);
    ll ans=0;
    FOR(i, 1, m) if(uni(e[i].u, e[i].v)) ans+=e[i].c;
    write(ans);
}