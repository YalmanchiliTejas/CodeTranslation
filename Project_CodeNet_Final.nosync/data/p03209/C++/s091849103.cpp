#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

map<pair<int,ll>,ll> dp;
ll num[60];

ll rec(int n,ll k){
    if(k==0)return 0;
    if(n==0)return k==1;
    if(dp[{n,k}])return dp[{n,k}];
    ll ret=0;
    ret+=rec(n-1,min(k-1,num[n-1]));
    if(k>=num[n-1]+2){
        ++ret;
        ret+=rec(n-1,min(num[n-1],k-num[n-1]-2));
    }
    return dp[{n,k}]=ret;
}

int main(){
    ll n,k;
    cin>>n>>k;
    num[0]=1;
    rep(i,50)num[i+1]=2*num[i]+3;
    cout<<rec(n,k)<<endl;
    return 0;
}
