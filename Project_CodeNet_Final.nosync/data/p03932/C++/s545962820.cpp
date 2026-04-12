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

int H,W;
int A[222][222];
int dp[222][222][444];
int solve(int x1,int x2,int t){
    int y1=t-x1;
    int y2=t-x2;
    int &ret=dp[x1][x2][t];
    if(ret!=-1)return ret;
    ret=0;
    if(t==H+W-2)return A[H-1][W-1];
    rep(i,2)rep(j,2){
        x1+=i;y1+=1-i;x2+=j;y2+=1-j;
        if(x1==W||x1==W||y1==H||y2==H||(x1==x2&&y1==y2));
        else{
            chmax(ret,solve(x1,x2,t+1));
        }
        x1-=i;y1-=1-i;x2-=j;y2-=1-j;
    }
    if(t==0)ret+=A[0][0];
    else ret+=A[y1][x1]+A[y2][x2];
    return ret;
}

signed main(){
    cin>>H>>W;
    rep(i,H)rep(j,W)cin>>A[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,0,0)<<endl;
    return 0;
}
