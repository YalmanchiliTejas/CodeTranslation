#include<iostream>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;
ll N,X;
ll height[51];
ll paty[51];
ll Func(ll eatNum,ll level){
    if(level==0){
        return 1;
    }
    eatNum--;
    if(eatNum==0)return 0;
    ll ret=0;
    if(eatNum<=height[level-1]){
        return ret+Func(eatNum,level-1);
    }else{
        eatNum-=height[level-1];
        ret+=paty[level-1];
    }
    eatNum--;
    ret++;
    if(eatNum==0)return ret;
    if(eatNum<=height[level-1]){
        return ret+Func(eatNum,level-1);
    }else{
        eatNum-=height[level-1];
        ret+=paty[level-1];
    }
    return ret;
}
int main(){
    cin>>N>>X;
    height[0]=1;
    paty[0]=1;
    for(ll i=1;i<=N;i++){
        height[i]=height[i-1]*2+3;
        paty[i]=paty[i-1]*2+1;
    }
    cout<<Func(X,N)<<endl;
    return 0;
}