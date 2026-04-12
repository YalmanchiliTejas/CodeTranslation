#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
#include<cassert>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct query{
    int y,x,s;
};

int n;
int a[6010];
int dp[2010][2010];
int ma[2010],M;
int cnt[2010][2010];
vector<query> kousin;

void add(int y,int x,int s){
    query q;q.y=y;q.x=x;q.s=s;
    kousin.push_back(q);
}

void flush(){
    while(!kousin.empty()){
        int y=kousin.back().y,x=kousin.back().x,s=kousin.back().s;
        dp[y][x]=max(dp[y][x],s);
        dp[x][y]=dp[y][x];
        ma[y]=max(ma[y],dp[y][x]);
        ma[x]=max(ma[x],dp[y][x]);
        M=max(M,dp[y][x]);
        kousin.pop_back();
    }
}

void solve(){
    cin >> n;
    rep(i,3*n){
        cin >> a[i];a[i]--;
    }
    a[3*n]=n;
    a[3*n+1]=n;
    rep(i,n+1){
        rep(j,n+1){
            dp[i][j]=-mod;
        }
        ma[i]=-mod;
    }
    dp[a[0]][a[1]]=0;
    dp[a[1]][a[0]]=0;
    ma[a[0]]=0;
    ma[a[1]]=0;
    int c=0;
    rep(i,n){
        int x=a[3*i+2],y=a[3*i+3],z=a[3*i+4];
        if(x==y && y==z) {
            c+=1;
            continue;
        }
        rep(_,3){
            int tmp=x;x=y;y=z;z=tmp;
            if(x==y){
                rep(k,n+1){
                    add(k,z,dp[k][x]+1);
                }
            }
            rep(k,n+1){
                add(k,x,ma[k]);
            }
            add(x,y,M);
            add(x,y,dp[z][z]+1);
        }
        flush();
        // rep(i,n+1){
        //     rep(j,n+1){
        //         cout << i << " " << j << " " << dp[i][j] << endl;
        //     }
        // }
    }
    int ans=0;
    rep(i,n+1){
        rep(j,n+1){
            ans=max(ans,c+dp[i][j]);
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}