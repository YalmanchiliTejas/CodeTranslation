#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)
#define RFOR(i,n,m) for(int i=(int)(n); i>=(int)(m); i--)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define RITR(x,c) for(__typeof(c.rbegin()) x=c.rbegin();x!=c.rend();x++)
#define setp(n) fixed << setprecision(n)

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define pi pair<int,int>

#define all(a) (a.begin()),(a.end())
#define rall(a) (a.rbegin()),(a.rend())
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ins insert

using namespace std;

//-------------------------------------------------

const int N_MAX = 2020;
const int INF = 1e9;
int a[3*N_MAX];
int dp[N_MAX][N_MAX];
int maxi[N_MAX];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin>>N;
    int x,y; cin>>x>>y;
    if (x>y) swap(x,y);
    rep(i,3*(N-1)) cin>>a[i];
    int z; cin>>z;

    rep(i,N+1)rep(j,N+1) dp[i][j]=-INF;
    rep(i,N+1) maxi[i]=-INF;
    dp[x][y] = 0;
    maxi[x] = maxi[y] = 0;
    int Max=0;
    int extra=0;
    using P = tuple<int,int,int>;
    // FOR(i,1,N)FOR(j,i,N) cout<<"dp("<<i<<","<<j<<") = "<<dp[i][j]<<endl;
    // FOR(i,1,N) cout<<"max("<<i<<") = "<<maxi[i]<<endl;
    // cout<<"--------------"<<endl;
    rep(i,N-1){
        int *v = &a[i*3];
        if (v[0]==v[1] && v[1]==v[2]){
            extra++;
            continue;
        }
        sort(v,v+3);
        bool aab = (v[0]==v[1]);
        bool abb = (v[1]==v[2]);
        int vsum=v[0]+v[1]+v[2];
        // cout<<"input: "<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
        queue<P> que;
        rep(j,3)FOR(k,1,N){
            int value = maxi[k];
            if (aab && j==2){
                int s = min(k,v[0]);
                int t = max(k,v[0]);
                chmax(value,dp[s][t]+1);
            }
            if (abb && j==0){
                int s = min(k,v[2]);
                int t = max(k,v[2]);
                chmax(value,dp[s][t]+1);
            }
            rep(x,3)FOR(y,x+1,2){
                if ((v[x]==k&&y==j) || (x==j&&v[y]==k)){
                    int z = vsum-v[x]-v[y];
                    chmax(value,max(dp[z][z]+1,Max));
                }
            }
            que.push({v[j],k,value});
        }
        while(!que.empty()){
            int s,t,score;
            tie(s,t,score) = que.front(); que.pop();
            if (s>t) swap(s,t);
            chmax(dp[s][t],score);
            chmax(Max,dp[s][t]);
            chmax(maxi[s],dp[s][t]);
            chmax(maxi[t],dp[s][t]);
        }
        // FOR(i,1,N)FOR(j,i,N) cout<<"dp("<<i<<","<<j<<") = "<<dp[i][j]<<endl;
        // FOR(i,1,N) cout<<"max("<<i<<") = "<<maxi[i]<<endl;
        // cout<<"--------------"<<endl;
    }
    int ans=0;
    rep(i,N+1)rep(j,N+1){
        chmax(ans,dp[i][j]+(i==j&&j==z));
    }
    ans+=extra;
    cout<<ans<<endl;
    return 0;
}
