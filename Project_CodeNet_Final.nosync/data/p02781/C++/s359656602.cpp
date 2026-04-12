#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;

ll dp[110][2][5];
string s;
ll K;
ll rec(ll digit,ll tight,ll num){
    if(digit == s.size()){
        if(num == K)return 1;
        else return 0;
    }
    if(num > K)return 0;
    ll x = s[digit]-'0';
    ll right = tight?x:9;
    ll &res = dp[digit][tight][num];
    if(~res)return res;
    res = 0;
    for(ll i=0;i<=right;i++){
        res +=rec(digit+1,tight&&(i==right),((i==0)?num:num+1));
    }
    return res;
}
 
int main(void){
    cin>>s;
    ll n = s.length();
    cin>>K;
    for(ll i=0;i<110;i++){
        for(ll j=0;j<2;j++){
            for(ll k=0;k<5;k++){
                dp[i][j][k]=-1;
            }
        }
    }
   cout<<rec(0,1,0)<<endl;
	return 0; 
}