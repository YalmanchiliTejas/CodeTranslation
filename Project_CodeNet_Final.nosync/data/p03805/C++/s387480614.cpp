#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
#define INT(x) int x; scanf("%d",&x)
#define INPUT(x) scanf("%d",&x)
#define REP1(x,n) for(int x = 0; x < n; x++)
#define REP2(x,s,e) for(int x = s; x <= e; x++)
#define RREP1(x,n) for(int x = n-1; x >= 0; x--)
#define RREP2(x,s,e) for(int x = s; x >= e; x--)
#define BR printf("\n")
#define INF 2000000000

typedef long long ll;

bool L[9][9] = {};
int pathcount = 0;
int M,N;

void dfs(int i, vector<bool> flag, int counter){
    if(counter == N){
        pathcount++;
        return;
    }
    flag[i] = 1;
    REP2(t,1,N){
        //パス通っていて，かつ行ったことがない．
        if (L[i][t] && !flag[t]) {
            dfs(t,flag,counter+1);
        }
    }
    
}

int main(){
    INPUT(N);INPUT(M);
    vector<bool> flag;
    REP1(i,N+1){
        flag.push_back(false);
    }
    REP1(i,M){
        INT(a);INT(b);
        L[a][b] = 1;
        L[b][a] = 1;
    }
    dfs(1,flag,1);
    cout << pathcount << endl;
    return 0;
}