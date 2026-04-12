#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i < n; i++)
#define repv(i,n) for(int i = n-1; i >= 0; i--)
#define fi first
#define sc second
#define pb push_back
using namespace std;
typedef long long ll;

char BUF[3500000];
inline void I(int&a){scanf("%d",&a);}
inline void I(int&a,int&b){scanf("%d%d",&a,&b);}
inline void I(int&a,int&b,int&c){scanf("%d%d%d",&a,&b,&c);}
inline void I(int&a,int&b,int&c,int&d){scanf("%d%d%d%d",&a,&b,&c,&d);}
inline void L(ll&a){scanf("%lld",&a);}
inline void L(ll&a,ll&b){scanf("%lld%lld",&a,&b);}
inline void L(ll&a,ll&b,ll&c){scanf("%lld%lld%lld",&a,&b,&c);}
inline void L(ll&a,ll&b,ll&c,ll&d){scanf("%lld%lld%lld%lld",&a,&b,&c,&d);}
inline void S(string&str){str.clear();scanf("%s",BUF);int s=strlen(BUF);rep(i,s)str.pb(BUF[i]);}
inline void SV(vector<int>&v){v.clear();scanf("%s",BUF);int s=strlen(BUF);rep(i,s)if('a'<=BUF[i]&&BUF[i]<='z')v.pb(BUF[i]-'a');else v.pb(BUF[i]-'A');}

const auto EPS = 1e-10;
const auto INF = 100000000;
const auto MOD = 1000000007;
typedef pair<ll,ll> P;

int n;
vector<int> e[100000];
bool col[100000];
bool dead[100000];
int dep[100000];
int sorter[100000];
int par[100000];

bool cmp(int left, int right){
    return dep[left] > dep[right];
}

void dfs(int v){
    rep(i,e[v].size()){
        if(dep[e[v][i]] != INF){
            par[v] = e[v][i];
            continue;
        }
        dep[e[v][i]] = dep[v]+1;
        dfs(e[v][i]);
    }
}

int main(){
    I(n);
    rep(i,n) dep[i] = INF;
    rep(i,n-1){
        int a, b;
        I(a, b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    rep(i,n) par[i] = -1;
    dep[0] = 0;
    dfs(0);
    rep(i,n) sorter[i] = i;
    sort(sorter, sorter+n, cmp);
    rep(ii,n){
        int i = sorter[ii];
        if(dead[i]) continue;
        if(par[i] != -1){
            if(dead[par[i]]){
                cout << "First" << endl;
                return 0;
            }
            dead[par[i]] = true;
        } else{
            cout << "First" << endl;
            return 0;
        }
        dead[i] = true;
    }
    cout << "Second" << endl;
}






























