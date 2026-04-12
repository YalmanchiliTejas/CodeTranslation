#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

ll dp[105][2][5];
string n;
ll k;

ll rec(ll digit,ll tight,ll num){
    if(num>k)return 0;
    if(digit == n.length()){
        if(num==k)return 1;
        else return 0;
    }
    ll x = n[digit]-'0';
    ll r = tight?x:9;
    ll &res = dp[digit][tight][num];
    if(res!=-1)return res;
    res = 0;
    for(ll i=0;i<=r;i++){
        ll ans = 0;
        if(i!=0)ans=1;
        res+=rec(digit+1,(tight==1) && (i==r),num+ans);
    }
    return res;
}

int main(void){
    for(ll i=0;i<105;i++){
        for(ll j=0;j<2;j++){
            for(ll l=0;l<5;l++){
                dp[i][j][l]=-1;
            }
        }
    }
    cin>>n>>k;
    cout<<rec(0,1,0)<<endl;
    return 0;
}