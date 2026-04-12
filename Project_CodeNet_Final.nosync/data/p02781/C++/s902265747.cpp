#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

string N;
ll K;
ll dp[110][2][5];
int main(){
    cin>>N>>K;
    for(ll i=0;i<N.length();i++){
        for(ll j=0;j<2;j++){
            for(ll k=0;k<4;k++){
                dp[i][j][k]=0;
            }
        }
    }
    dp[0][0][0]=1;
    for(ll i=0;i<N.length();i++){
        for(ll j=0;j<2;j++){
            for(ll k=0;k<=K;k++){
                for(ll d=0;d<10;d++){
                    ll nextI=i+1;
                    ll nextJ=j;
                    if(j==0){
                        if(N[i]-'0'<d)continue;
                        if(N[i]-'0'>d){
                            nextJ=1;
                        }
                    }
                    ll nextK=k+(d>0);
                    if(nextK>K)continue;
                    dp[nextI][nextJ][nextK]+=dp[i][j][k];
                }
            }
        }        
    }
    cout<<dp[N.length()][0][K]+dp[N.length()][1][K]<<endl;
    return 0;
}