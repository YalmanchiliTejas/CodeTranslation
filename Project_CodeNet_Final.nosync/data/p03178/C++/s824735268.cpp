#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=long long;
using P=pair<int,int>;
const ll INF=1LL<<30;
const ll LINF=1LL<<61;
const double eps=1e-5;
const ll MOD=1e9+7;
string s;
int d,n;
ll dp[10010][110][2];
ll dfs(int i,int sum,bool f){
    if(dp[i][sum][f]!=-1)return dp[i][sum][f];
    if(i==n){
        if(sum==0){
            return 1LL;
        }else{
            return 0LL;
        }
    }
    int a=s[i]-'0';
    ll res=0;
    if(f){
        for(int j=0;j<a;j++){
            res+=dfs(i+1,(sum+j)%d,false);
            res%=MOD;
        }
        res+=dfs(i+1,(sum+a)%d,f);
        res%=MOD;
    }else{
        for(int j=0;j<10;j++){
            res+=dfs(i+1,(sum+j)%d,false);
            res%=MOD;
        }
    }
    return dp[i][sum][f]=res;
}
int main(){
    cin>>s;
    memset(dp,-1,sizeof(dp));
    n=s.length();
    cin>>d;
    cout<<(dfs(0,0,1)-1+MOD)%MOD<<endl;
}   
