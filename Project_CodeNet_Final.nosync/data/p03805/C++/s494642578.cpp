#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
typedef long long ll;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define rrep(i,n,a) for(int i=n;i>=a;i--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(s) s.begin(),s.end()
#define lla(s) s.rbegin(),s.rend()
#define pcnt(b) __builtin_popcount(b)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<pair<int,int>>
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const ll INF = 1e18;

int g[10][10]={},n,m,a,b,ans=0;


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    memset(g,0,sizeof(g));
    rep(i,0,m){
        cin>>a>>b;
        a--;b--;
        g[a][b]=1;
        g[b][a]=1;
    }
    vi p(n-1);
    rep(i,1,n){
        p[i-1]=i;
    }
    bool f = 1;
    if(!g[0][p[0]]){f=0;}
    rep(i,0,n-2){if(!g[p[i]][p[i+1]]){f=0;}}
    if(f){ans++;}
    while(next_permutation(all(p))){
        if(!g[0][p[0]]){continue;}
        else{
            f = 1;
            rep(i,0,n-2){
                if(!g[p[i]][p[i+1]]){f=0;}
            }
            if(f){ans++;}
        }
    }
    cout<<ans<<endl;
}