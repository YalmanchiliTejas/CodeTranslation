#include <iostream>
#include <cstring>
#include <cstdio>
#include<cstdint>
#include <utility>
#include <algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
#define rep(i, n) for (int i = 0; i < n; i++)
#define reprev(i, n) for (int i = n - 1; i >= 0; i--)
#define MAX 100100
#define MAX_N 200100
#define SENTINEL 2000000000
const int MOD = 1e9+7;
#define NIL -1
const int INF = 1 << 29;
int n,m;
bool matrix[50][50];
int a,b;
bool visited[50];


int dfs(int v){
    bool all_visited=true;
    rep(i,n){
        if(visited[i]==false)all_visited=false;
        }
        if(all_visited){
            return 1;
        }
        int ret=0;
        rep(i,n){
            if(matrix[v][i]==false)continue;
            if(visited[i]==1)continue;
            visited[i]=true;
            ret+=dfs(i);
            visited[i]=false;
        }
        return ret;
    }

int main(){
    memset(visited,0,sizeof(visited));
visited[0]=1;
    cin>>n>>m;
    rep(i,m){
        cin>>a>>b;
        matrix[a-1][b-1]=matrix[b-1][a-1]=true;
    }
    cout<<dfs(0)<<endl;
    return 0;
}