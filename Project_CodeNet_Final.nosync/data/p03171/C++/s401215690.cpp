/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <utility>
#include <stack>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rep3(var, min, max) for (ll (var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll (var) = (max) - 1; (var) + 1 > (min); --(var))
#define Mp(a,b) make_pair((a),(b))
#define F first
#define S second
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll MOD = 1e9 + 7;
int main(){
    int n;cin>>n;
    V vec(n);
    rep(i,n)cin>>vec[i];
    VV dp(n+1,V(n+1));//[i,j)の範囲
    for(int i=1;i<=n;i++){//length小さいほうから
        for(int j=0;j+i<=n;j++){//左
            int k=i+j;//右
            if((n-i)%2==0){//先手 遷移するイメージ
                dp[j][k]=max(dp[j+1][k]+vec[j],dp[j][k-1]+vec[k-1]);
            }else{//後手
                dp[j][k]=min(dp[j+1][k]-vec[j],dp[j][k-1]-vec[k-1]);
            }
        }
    }
    cout<<dp[0][n]<<endl;
}
