#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<deque>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#define rep(i,n) for(int i=0;i<n;i++)

typedef int long long ll;
using namespace std;
typedef pair<int,int> P;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll MOD=1e9+7;
static const int MAX = 100;
static const int INF = (1<<23);
template<class T> T gcd(T a, T b){return b? gcd(b,a%b) : a;}
template<class T> T lcm(T a,T b){return a / gcd(a,b)*b;}

int main(){
    string s;
    int k;
    cin>>s>>k;
    ll n=s.size();
    ll dp[101][4][2] = {};
    dp[0][0][0]=1;
    dp[0][0][1]=0;


   for(int i=1;i<=n;i++){
        rep(j,4){
            int x = s[i-1]-'0';
            if(x==0){
                dp[i][j][0] += dp[i-1][j][0];
            }else{
               // ll l=max(0,j-1);
                if(j!=0){
                    dp[i][j][0] += dp[i-1][j-1][0];
                }


            }


            for(int k=0;k<=x-1;k++){
                if(k==0){
                    dp[i][j][1] += dp[i-1][j][0];
                }else{
                   if(j==0){
                      // dp[i][j][1]+=dp[i-1][j][0];
                   }else{
                       dp[i][j][1]+=dp[i-1][j-1][0];
                   }

                }
            }

            for(int k=0;k<=9;k++){
                if(k==0){
                    dp[i][j][1]+=dp[i-1][j][1];
                }else{
                    if(j==0){
                       // dp[i][j][1]+=dp[i-1][j][1];
                    }else{
                        dp[i][j][1]+=dp[i-1][j-1][1];
                    }
                }
            }
        }
    }


    cout<<dp[n][k][0]+dp[n][k][1]<<endl;
  



    
return 0;
}
