#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const int INF=2e9;

int main(){
    string s;cin>>s;
    int k;cin>>k;
    int n=s.size();
    if(n<k){
      cout<<0<<endl;
      return 0;
    }
    ll dp[n+1][n+1][2];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k]=0;
            }
        }
    }
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int h=0;h<2;h++){
                for(int d=0;d<=(h==1?9:(int)(s[i]-'0'));d++){
                    dp[i+1][j+(d>0?1:0)][h||(d<(int)(s[i]-'0'))]+=dp[i][j][h];
                }
            }
        }
    }
    cout<<dp[n][k][0]+dp[n][k][1]<<endl;
    return 0;
}