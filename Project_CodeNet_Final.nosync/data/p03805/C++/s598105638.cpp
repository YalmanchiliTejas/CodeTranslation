#include <bits/stdc++.h>
#define rep(i,a) for(int i=0;i<int(a);++i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
using ll = long long;
using itn = int;
using namespace std;
static const long double GRATIO=(long double)(1+sqrt(5))/2;
ll GCD(ll a, ll b){
    return b ? GCD(b, a%b) : a;
}
ll LCM(ll a, ll b){
    return a/GCD(a,b)*b;
}
int dfs(vector<vector<int>> &G, vector<bool> visit, int v, int N, int cnt){
    visit.at(v)=true;
    cnt++;
    if(cnt==N){
        return 1;
    }
    int ans=0;
    for(int u:G.at(v)){
        if(visit.at(u)) continue;
        ans+=dfs(G,visit,u,N,cnt);
    }
    return ans;
}
int main(){
    int N,M;
    cin>>N>>M;
    vector<int> a(M),b(M);
    vector<vector<int>> G(N);
    rep(i,M){
        int from,to;
        cin>>from>>to;
        from--;
        to--;
        G.at(from).push_back(to);
        G.at(to).push_back(from);
    }
    vector<bool> visit(N,false);
    int ans=dfs(G,visit,0,N,0);
    cout<<ans<<endl;
}

