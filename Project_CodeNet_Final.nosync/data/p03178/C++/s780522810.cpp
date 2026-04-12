#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

ll dp[10010][2][101];
string s;
int d;
int flag[10010][2][101];

ll ddpp(int i,int sm,int j){
    int n=s.size();
    if (flag[i][sm][j])return dp[i][sm][j];
    flag[i][sm][j]=1;
    if (sm==1){//sより小さい
        if (i==n-1){
            for (int k=0;k<10;k++){
                if (k%d==j)dp[i][sm][j]+=1;
            }
        }
        else{
            for (int k=0;k<10;k++){
                dp[i][sm][j]+=ddpp(i+1,sm,(j-k+100*d)%d);
                dp[i][sm][j]%=MOD;
            }
        }
        return dp[i][sm][j];
    }
    else{
        int num=s[i]-'0';
        if (i==n-1){
            for (int k=0;k<num+1;k++){
                if (k%d==j) {
                    dp[i][sm][j]+=1;
                }
            }
            return dp[i][sm][j];
        }
        for (int k=0;k<num;k++){
            dp[i][sm][j]+=ddpp(i+1,1,(j-k+10*d)%d);
            dp[i][sm][j]%=MOD;
        }
        dp[i][sm][j]+=ddpp(i+1,sm,(j-num+10*d)%d);
        dp[i][sm][j]%=MOD;
        return dp[i][sm][j];
    }
}

int main() {
    cin>>s;
    cin>>d;
    int num=s.size();
    ddpp(0,0,0);
    ll ans1=dp[0][0][0];
    memset(dp,0,sizeof(dp));
    memset(flag,0,sizeof(0));
    ll ans2=ddpp(0,1,0);
    ans2=dp[0][1][0];
    cout<<(ans1-1+MOD)%MOD<<endl;

    

    return 0;
}