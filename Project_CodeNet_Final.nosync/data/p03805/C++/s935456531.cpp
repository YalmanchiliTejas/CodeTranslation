#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define p(s) cout<<(s)<<endl
#define REP(i,n,N) for(int i=n;i<N;i++)
#define RREP(i,n,N) for(int i=N-1;i>=n;i--)
#define CK(n,a,b) ((a)<=(n)&&(n)<(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;

int N,M;
vector<int> edge[60];
int cnt;
void dfs(int node, vector<bool> visited){

    for(auto next: edge[node]){
        if(!visited[next]){
            visited[next] = true;
            bool flag=true;
            REP(i,0,N) {
                if(!visited[i]){
                    flag=false;
                    break;
                }
            }
            if(flag) cnt++;
            dfs(next,visited);
            visited[next] = false;
        }
    }
}

int main() {
    cin>>N>>M;
    REP(i,0,M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<bool> visited(N,false);
    visited[0]=true;
    dfs(0,visited);
    p(cnt);
    return 0;
}