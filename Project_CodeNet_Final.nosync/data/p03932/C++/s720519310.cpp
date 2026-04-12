#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int mod=1000000007;
inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

const int INF=1001001001001001001ll;

int H,W;
int A[222][222];

int dp[222][222][222];
signed main(){
    cin>>H>>W;
    rep(i,H){
        rep(j,W)cin>>A[i][j+1],A[i][j+1]+=A[i][j];
    }
    fill_n(**dp,222*222*222,-INF);
    dp[0][0][0]=0;

    for(int i=0;i<H;i++){
        int max1=-INF;
        int max2[222]={};fill_n(max2,222,-INF);
        for(int j=0;j<W;j++){
            for(int k=0;k<=j;k++)chmax(max1,dp[i][k][j]-A[i][k]);
            for(int k=j+1;k<W;k++)chmax(max2[k],dp[i][j][k]-A[i][j]-A[i][k]);
            int max3=-INF;
            for(int k=j;k<W;k++){
                if(k!=j)chmax(max3,max2[k]);
                chmax(dp[i+1][j][k],max1+A[i][k+1]);
                chmax(dp[i+1][j][k],max3+A[i][k+1]+A[i][j+1]);
            }
        }
    }
    cout<<dp[H][W-1][W-1]<<endl;
    return 0;
}
