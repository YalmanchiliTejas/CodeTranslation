#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using ll=long long;
static const ll mod = 1e9 + 7;
static const ll INF = 1LL << 50;
using namespace std;

ll dp[3005][3005];//石の数が残りi個のときの勝敗を表すdp[i]
vector<int>a;

ll rec(int l,int r){
    if(dp[l][r]>-1)return dp[l][r];
    ll res;
    if(l==r)res=a[l];
    else res=max(a[r]-rec(l,r-1),a[l]-rec(l+1,r));
    return dp[l][r]=res;
}
//自分の得点-相手の得点の最大化
int main(){
    int n;
    cin>>n;
    a.resize(n);
    rep(i,n)cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
    return 0;
}
