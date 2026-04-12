#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<climits>
#include<queue>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
typedef pair<ll,ll> LLP;
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
#define INF 1000000007
#define MOD 1000000007
#define ARRAY_MAX 15



int n,m;
bool mp[ARRAY_MAX][ARRAY_MAX];

int dfs(int now,int n,vector<bool>& visited){
    //今いる位置、頂点の数、訪れたかのチェック配列

    int sum = 0;//この再帰から得られる経路数

    bool all_visited = true;//全て訪れたか

    REP(i,n){
        if(visited[i] == false){
            all_visited = false;
            break;
        }
    }

    if(all_visited){
        return 1;
    }

    REP(i,n){
        if(mp[now][i] == false){
            //経路がない
            continue;
        }
        if(visited[i] == true){
            //既に訪れている
            continue;
        }
        visited[i] = true;//訪れたことにして潜る
        sum += dfs(i,n,visited);//訪れるとして再帰
        visited[i] = false;//訪れないで別の経路でできるかを試す
    }
    return sum;
}


int main(){

    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        mp[a][b] = true;
        mp[b][a] = true;
    }

    vector<bool> visited(ARRAY_MAX,false);
    REP(i,n){
        visited[i]=false;
    }
    visited[0] = true;
    cout << dfs(0,n,visited) << endl;

    return 0;
}