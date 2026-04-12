#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define USE_LLONG_AS_INT
#ifdef USE_LLONG_AS_INT
#define int long long
#define inf (1ll<<60)
#else
#define inf (1<<30)
#endif
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int>>
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define MEMSET(a) memset(a,0,sizeof(a))
#define Yes(f) cout<<(f?"Yes":"No")<<endl
#define yes(f) cout<<(f?"yes":"no")<<endl
#define YES(f) cout<<(f?"YES":"NO")<<endl
#define SORT(v) sort(all(v))
#define RSORT(v) sort(all(v), greater<int>())

using namespace std;

const int mod=1e9+7;
const string sp=" ";

void run();

void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(12);
}

signed main(){
    init();
    run();
    return 0;
}

void run(){
    int n,m,k;
    cin>>n>>m>>k;
    vi d(m);
    rep(i,m){
        cin>>d[i];
        d[i]--;
    }
    vvi v(n,vi(k));
    rep(i,n)rep(j,k){
        cin>>v[i][j];
        v[i][j]--;
    }
    int id[n];
    memset(id,-1,sizeof(id));
    rep(i,m)id[d[i]]=i;
    int dp[1<<m];
    memset(dp,-1,sizeof(dp));
    dp[(1<<m)-1]=0;
    queue<int> q;
    q.push((1<<m)-1);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        rep(i,k){
            int ns=s;
            int mask=0;
            rep(j,m){
                if((s>>j)&1){
                    ns^=(1<<j);
                    if(~id[v[d[j]][i]])mask|=1<<id[v[d[j]][i]];
                }
            }
            ns|=mask;
            if(!~dp[ns]&&s!=ns){
                dp[ns]=dp[s]+1;
                q.push(ns);
            }
        }
    }
    cout<<dp[0]<<endl;
}
