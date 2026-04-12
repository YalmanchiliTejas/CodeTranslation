#include<iostream>
#include<set>
#include <bitset>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include<string.h>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
#include <limits>
#include <numeric>
#include <type_traits>
#define int long long
#define ll long long
#define mod  1000000007
#define MOD  1000000007
#define inf 1e17
#define rep(i,j,n) for(int i=j;i<n;i++)
#define P pair<int,int>
#define ps push_back
#define all(x) x.begin(),x.end()
double pi = 3.141592653589793;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//ここから始めよう
string k;int d;
int dp[11111][111][2];
int dfs(int i,int amari,bool ok){
    if(i<0)return amari%d==0;
    int e=ok?k[i]-'0':9;
    int &ret=dp[i][amari][ok];
    if(~ret)return ret;
    ret=0;
    //cout<<"k["<<i<<"]="<<k[i]<<" 余りは"<<amari<<" "<<ok<<" "<<e<<endl;
    for(int s=0;s<=e;s++){
        (ret+=dfs(i-1,(amari+s)%d,s==e&&ok))%=mod;
    }
    return ret;
}
signed main(){
    cin>>k>>d;
    reverse(k.begin(),k.end());
    memset(dp,-1,sizeof(dp));
    cout<<(dfs(k.size()-1,0,1)+mod-1)%mod<<endl;return 0;
}