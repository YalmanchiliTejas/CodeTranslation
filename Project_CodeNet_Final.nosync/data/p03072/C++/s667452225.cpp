#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
const ll MAX_N=20;
ll N,H[MAX_N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll ans=0;
    cin>>N;
    REP(i,N){
        cin>>H[i];
        bool f=true;
        REP(j,i){
            if(H[j]>H[i]){
                f=false;
            }
        }
        if(f)ans++;
    }
    cout<<ans<<endl;
}
