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

ll N;
string s;
ll anim[100010];
bool Check(){
    for(ll i=1;i<N-1;i++){
        if(s[i]=='o'){
            if(anim[i]==0){//羊
                anim[i+1] = anim[i-1];
            }else{
                anim[i+1] = (anim[i-1]+1)%2;
            }
        }else{
            if(anim[i]==0){//羊
                anim[i+1] = (anim[i-1]+1)%2;
            }else{
                anim[i+1] = anim[i-1];
            }
        }
    }
    if(s[0]=='o'){
        if(anim[0]==0){
            if(anim[N-1]!=anim[1])return false;
        }else{
            if(anim[N-1]==anim[1])return false;
        }
    }else{
        if(anim[0]==1){
            if(anim[N-1]!=anim[1])return false;
        }else{
            if(anim[N-1]==anim[1])return false;
        }
    }

    if(s[N-1]=='o'){
        if(anim[N-1]==0){
            if(anim[N-2]!=anim[0])return false;
        }else{
            if(anim[N-2]==anim[0])return false;
        }
    }else{
        if(anim[N-1]==1){
            if(anim[N-2]!=anim[0])return false;
        }else{
            if(anim[N-2]==anim[0])return false;
        }
    }
    return true;
}
int main(){
    cin>>N>>s;
    for(ll i=0;i<4;i++){
        anim[0]=i/2;
        anim[1]=i%2;
        if(Check()){
            for(ll i=0;i<N;i++){
                cout<<(anim[i]==0?"S":"W");
            }
            return 0;
        }
    }
    cout<<-1;
    
    return 0;
}