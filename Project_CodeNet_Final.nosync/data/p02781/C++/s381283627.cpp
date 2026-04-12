#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    string n;cin>>n;
    int m=n.size();
    int k;cin>>k;
    vector<vector<vector<int>>> dp(105, vector<vector<int>>(5, vector<int>(2)));
    dp[0][0][0]=1;
    int tmp;
    rep(i,m)rep(j,k+1){
        dp[i+1][j][1]+=dp[i][j][1];
        dp[i+1][j+1][1]+=9*dp[i][j][1];
        tmp=n[i]-'0';
        if(tmp==0)dp[i+1][j][0]=+dp[i][j][0];
        else{
            dp[i+1][j][1]+=dp[i][j][0];
            dp[i+1][j+1][1]+=(tmp-1)*dp[i][j][0];
            dp[i+1][j+1][0]+=dp[i][j][0];
        }
    }
    cout<<dp[m][k][0]+dp[m][k][1]<<endl;
}