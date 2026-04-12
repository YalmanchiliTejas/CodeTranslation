//
//  main.cpp
//  ProCon
//
//  Created by hashimotoryoma on 2017/08/20.
//  Copyright © 2017年 hashimotoryoma. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <vector>

#define repeat(i,n) for (int i = 0; (i) < (n); ++ (i))

using namespace std;

typedef long long ll;

int isvisted=0;
int allvisted;
int ans=0;
int N,M;
bool graph[10][10];

int cnt=0;
void dfs(int v){
    if(isvisted == allvisted){
        ans++;
        return;
    }
    repeat(i, N){
        if((isvisted>>i)&1 || !graph[v][i])
            continue;
        isvisted |= 1<<i;
        dfs(i);
        isvisted -= 1<<i;
    }
    return;
}

int main() {
    // insert code here...    return 0;
    //////
    // input from txt
    /*
     std::ifstream in("input.txt");
     std::cin.rdbuf(in.rdbuf());
     std::ofstream out("output.txt");
     std::cout.rdbuf(out.rdbuf());
     ////
     */
    cin >> N >> M;
    allvisted = (1<<N) - 1;
    repeat(i,N){
        repeat(j,N){
            graph[i][j] = false;
        }
    }
    
    repeat(i, M){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    isvisted = 1;
    ans = 0;
    dfs(0);
    cout << ans << endl;
    return 0;
}
