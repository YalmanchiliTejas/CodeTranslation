#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>

const int MOD = pow(10,9)+7;
typedef long long ll;

using namespace std;
int in(){
    int temp;
    scanf("%d",&temp);
    return temp;
}

ll lin(){
    ll temp;
    scanf("%lld",&temp);
    return temp;
}


int ans = 0;

void dfs(int *visited, int cur, vector<int> *links, int N){
    
    int sum=0;
    for(auto i = 1; i <= N ; i++){
        sum+=visited[i];
    }
    
    if(sum == N){
        ans ++;
        return;
    }

    for(auto next : links[cur]){
        
        if (visited[next] == 1){
            continue;
        }
        
        visited[next] = 1;
        dfs(visited,next,links,N);
        visited[next] = 0;
    }
    
    return;
    
}



int main() {

    int N = in(); int M = in();
    
    typedef pair<int, int> P;
    
    vector<int> links[N+1];
    
    P temp;
    for(auto i = 0; i<M; i++){
        cin >> temp.first >> temp.second;
        links[temp.first].push_back(temp.second);
        links[temp.second].push_back(temp.first);
    }
    
    
    int visited[N+1];
    for(auto i = 1; i <=N; i++){
        visited[i] = 0;
    }
    
    visited[1] = 1;
    
    dfs(visited,1,links,N);
    
    cout << ans << endl;
    
    return 0;
    
}



