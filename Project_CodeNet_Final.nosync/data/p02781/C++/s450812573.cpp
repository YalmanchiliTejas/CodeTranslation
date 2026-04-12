#include <bits/stdc++.h>
using namespace std;
#define int long long
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(0),cin.tie(0);
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define mt make_tuple
#define all(a) a.begin(),a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))
#define gg exit(0);

const int N=2010;

int n,k;
int a[N];
int f[N][2][10];
string s;

int dfs(int i,int o,int s){
    if(s>k) return 0;
    if(i>n) return s==k;
    int &ret=f[i][o][s]; if(ret>-1) return ret; ret=0;
    forinc(j,0,o?9:a[i]){
        ret+=dfs(i+1,o|(j<a[i]),s+(!!j));
    }
    return ret;
}

main(){
    #define task "TASK"
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    fasty;

    reset(f,-1);
    cin>>s>>k; n=s.size();
    forinc(i,1,n) a[i]=s[i-1]-'0';

    cout<<dfs(1,0,0);
}
