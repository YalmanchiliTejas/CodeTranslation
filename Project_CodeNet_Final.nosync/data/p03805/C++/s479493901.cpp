#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
 
using namespace std;
#define REP(i,b,e) for(int i=(int)b;i<(int)e;i++)
#define rep0(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n+1)

#define shosu setprecision(10)

typedef long long ll;
ll longinf=1ll<<60;
int inf=1<<29;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


bool connect[9][9];
bool visited[9];
int N,M;
int ans;
void dfs(int i,int cnt){
    if(cnt==N) ans++; 
    visited[i]=true;
    rep0(j,N){
        if(connect[i][j]&&!visited[j]){
            dfs(j,cnt+1);
        }
    }
    visited[i]=false;
}


int main(){
    cin>>N>>M;
    rep0(i,M){
        int a,b;
        cin>>a>>b;
        connect[a-1][b-1]=connect[b-1][a-1]=true;
    }
    dfs(0,1);
    cout<<ans<<endl;

    return 0;
}