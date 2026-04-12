#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;
const int limit=100010;

signed main(){
    int N;cin>>N;
    vector<int>Keep;
    int ans=1;
    REP(i,N){
        int a;cin>>a;
        if(i==0)Keep.pb(a);
        else{
            auto v=lower_bound(Keep.rbegin(),Keep.rend(),a);
            if(v!=Keep.rbegin()){
                v--;
                *v=a;
            }
            else Keep.eb(a);
        }
    }
    cout<<Keep.size()<<endl;
}