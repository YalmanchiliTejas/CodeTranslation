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
int n,a[3333],dp[3333][3333];
int dfs(int i,int j,bool k){
    int &ret=dp[i][j];
    if(~ret)return ret;
    if(i==j){
        return ret=(k?a[i]:0);
    }
    if(k){
        return ret=max(dfs(i+1,j,0)+a[i],dfs(i,j-1,0)+a[j]);
    }else{
        return ret=min(dfs(i+1,j,1),dfs(i,j-1,1));
    }
}
signed main(){
    cin>>n;
    int sum=0;
    rep(i,0,n){
        cin>>a[i];sum+=a[i];
    }
    rep(i,0,3333)rep(j,0,3333)dp[i][j]=-1;

    cout<<dfs(0,n-1,1)-(sum-dfs(0,n-1,1))<<endl;return 0;
}