#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 4050
#define INF 1000000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 1000000007;
ll dp[MAX][105];
int main(){
    string s;
    int d;
    cin>>s>>d;
    int same=0;
    REP(i,SZ(s)){
        REP(j,d){
            REP(k,10){
                dp[i+1][(j+k)%d]+=dp[i][j];
                dp[i+1][(j+k)%d]%=MOD;
            }
        }
        REP(j,s[i]-'0'){
            dp[i+1][(same+j)%d]++;
            dp[i+1][(same+j)%d]%=MOD;
        }
        same=(same+s[i]-'0')%d;
    }
    if(same==0)dp[SZ(s)][0]++;
    dp[SZ(s)][0]=(dp[SZ(s)][0]-1+MOD)%MOD;
    OUT(dp[SZ(s)][0]);
    return 0;
}