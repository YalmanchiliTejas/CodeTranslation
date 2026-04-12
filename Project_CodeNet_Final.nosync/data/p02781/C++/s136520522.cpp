#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int main(void){
    string N;
    int K;
    cin >> N >> K;
    int L=N.length();
    lint dp[L+1][4][2]={};
    dp[0][0][0]=1;
    rep(i,L) rep(j,4) rep(k,2){
        int digit=N[i]-'0';
        rep(d,10){
            int i2=i+1,j2=j,k2=k;
            if(d!=0) j2++;
            if(j2>K) continue;
            if(k==0){
                if(d>digit) continue;
                if(d<digit) k2=1;
            }
            dp[i2][j2][k2]+=dp[i][j][k];
        }
    }
    cout << dp[L][K][0]+dp[L][K][1] << endl;
}