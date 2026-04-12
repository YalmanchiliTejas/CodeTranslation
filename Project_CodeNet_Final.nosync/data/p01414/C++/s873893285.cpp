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

int n;
int h[20],w[20];
const int H=4,W=4;
int ans=16;

set<string> used;

int dfs(string s){
    vector<int> dist(1<<16,inf);
    dist[0]=0;
    queue<int> que;
    que.push(0);
    while(que.size()){
        int cur=que.front();que.pop();
        rep(i,n){
            REP(j,-h[i]+1,H)REP(k,-w[i]+1,W){;
                int nxt=cur;
                int mask=0;
                rep(l,h[i])rep(m,w[i]){
                    if(0<=j+l&&j+l<H&&0<=k+m&&k+m<W&&!(cur&(1<<((j+l)*H+k+m)))){
                        nxt+=(1<<((j+l)*H+k+m));
                        mask|=(s[(j+l)*H+k+m]=='R')*4;
                        mask|=(s[(j+l)*H+k+m]=='G')*2;
                        mask|=(s[(j+l)*H+k+m]=='B')*1;
                    }
                }
                if(mask!=1&&mask!=2&&mask!=4)continue;
                if(dist[nxt]==inf){
                    dist[nxt]=dist[cur]+1;
                    que.push(nxt);
                }
            }
        }
    }
    return dist[65535];
}


int main(){
    cin>>n;
    rep(i,n){
        cin>>h[i]>>w[i];
    }
    string s;
    rep(i,4){
        string t;
        cin>>t;
        s+=t;
    }
    cout<<dfs(s)<<endl;
    return 0;
}
