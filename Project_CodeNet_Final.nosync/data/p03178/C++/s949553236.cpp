#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define eps LDBL_EPSILON
#define moder 1000000007
#define int long long
#define double long double
#define ll long long
#define INF LLONG_MAX/3
#define P pair<int,int>
#define prique priority_queue<int,vector<int>,greater<int>>
#define ggr getchar();getchar();return 0;
using namespace std;
string s;
int d;
int dp[10010][110][2];
signed main(){
    cin>>s>>d;
    dp[0][0][1]=1;
    rep(i,s.size()){
        rep(j,d){
            rep(k,10){
                if(s[i]==k+'0')dp[i+1][(j+k)%d][1]+=dp[i][j][1];
                else if(s[i]>k+'0')dp[i+1][(j+k)%d][0]+=dp[i][j][1];
                dp[i+1][(j+k)%d][0]+=dp[i][j][0];
                dp[i+1][(j+k)%d][0]%=moder;
                dp[i+1][(j+k)%d][1]%=moder;
            }
        }
    }
    cout<<(dp[s.size()][0][0]+dp[s.size()][0][1]-1+moder)%moder<<endl;
    ggr;
}