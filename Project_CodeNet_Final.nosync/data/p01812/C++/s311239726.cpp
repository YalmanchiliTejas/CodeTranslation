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
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
 
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int a[m];
    rep(i,m){
        cin>>a[i];
        --a[i];
    }
    map<int,int> mp;
    rep(i,m)mp[a[i]]=i;
    int v[n][k];
    rep(i,n){
        rep(j,k){
            cin>>v[i][j];
            --v[i][j];
        }
    }
 
    int all=1<<m;
    vector<int> dist(all,inf);
    dist[all-1]=0;
    queue<int> que;
    que.push(all-1);
    while(que.size()){
        int p=que.front();
        que.pop();
        vector<int> cur;
        rep(i,m){
            if(p&(1<<i))cur.push_back(a[i]);
        }
        rep(i,k){
            int nxt=0;
            for(auto e : cur){
                if(mp.count(v[e][i])){
                    nxt|=1<<mp[v[e][i]];
                }
            }
            if(dist[nxt]>dist[p]+1){
                dist[nxt]=dist[p]+1;
                que.push(nxt);
            }
        }
    }
    cout<<dist[0]<<endl;
    return 0;
}
