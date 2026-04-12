#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,0,n+1)
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
const int MOD=1e9+7;
const int INF=1e18;

signed main(){
    int N;cin>>N;
    vector<int>memo(26,0);
    vector<int>ans(26,INF);
    REP(i,N){
        string S;cin>>S;
        REP(j,26)memo[j]=0;
        for(int j=0;j<S.size();j++){
            memo[(int)(S[j]-'a')]++;
        }
        REP(j,26)ans[j]=min(ans[j],memo[j]);
    }
    string aS="";
    REP(i,26){
        REP(j,ans[i])aS+=(char)('a'+i);
    }
    cout<<aS<<endl;
}