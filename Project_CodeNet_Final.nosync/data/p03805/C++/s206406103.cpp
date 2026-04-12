#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
 
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SWAP(a,b) (a += b,b = a - b,a -= b)
#define ll long long

const int MOD = 1e9 + 7;
const int MAX_N = 8;
bool graph[MAX_N][MAX_N];
bool visited[MAX_N];

int n, m;
int ans = 0;

void dfs(int curN){
    bool flag = true;
    REP(i, n) {
        if(!visited[i]) {
            flag = false;
            break;
        }
    }
    if(flag) {
        ans++;
        return;
    }

    REP(i, n) {
        if(!graph[curN][i]) continue;
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i);
        visited[i] = false;
    }
}

int main() {
    cin >> n >> m;
    int a, b;
    REP(i, m) {
        cin >> a >> b;
        graph[a-1][b-1] = true;
        graph[b-1][a-1] = true;
    }
    REP(i, n) {
        visited[i] = false;
    }
    visited[0] = true;
    dfs(0);
    cout << ans << endl;
}