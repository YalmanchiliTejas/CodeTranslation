#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int H,W;
int A[222][222];

int dp[444][222][222];

signed main(){
    cin>>H>>W;
    rep(i,H)rep(j,W)cin>>A[i][j];

    for(int i=0;i<H+W-2;i++){
        for(int j=0;j<=i&&j<W;j++){
            for(int k=0;k<=i&&k<W;k++){
                int x1=j,y1=i-j;
                int x2=k,y2=i-k;

                rep(b,4){
                    int nx1=x1,ny1=y1;
                    int nx2=x2,ny2=y2;

                    if(b&1)nx1++;
                    else ny1++;

                    if(b>>1&1)nx2++;
                    else ny2++;

                    if(nx1>=W||ny1>=H||nx2>=W||ny2>=H)continue;
                    if(nx1!=nx2||ny1!=ny2)chmax(dp[i+1][nx1][nx2],dp[i][j][k]+A[ny1][nx1]+A[ny2][nx2]);
                    else chmax(dp[i+1][nx1][nx2],dp[i][j][k]+A[ny1][nx1]);
                }
            }
        }
    }

    cout<<dp[H+W-2][W-1][W-1]+A[0][0]<<endl;
    return 0;
}
