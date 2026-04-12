#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

vector<int> vi[8];
bool used[8];
int n,m;
int dfs(int s,int cnt){
    int res=0;
    if(cnt==n) return 1;
    rep(i,vi[s].size()){
        if(!used[vi[s][i]]){
            used[vi[s][i]]=true;
            res+=dfs(vi[s][i],cnt+1);
            used[vi[s][i]]=false;
        }
    }
    return res;
}
int main(){
    int sr,ds;
    cin>>n>>m;
    rep(i,m){
        cin>>sr>>ds;
        vi[sr-1].pb(ds-1);
        vi[ds-1].pb(sr-1);
    }
    int ans=0;
    used[0]=true;
    cout<<dfs(0,1)<<endl;
    return 0;
}