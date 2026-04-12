#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

using namespace std;

#define x first
#define y second
#define NMAX 100005
#define INF 1000000007

int n, viz[NMAX], subTree[NMAX]; 
vector<int> graph[NMAX];

void dfs(int node) {
    viz[node] = 1;
    subTree[node] = 1;
    
    int lim = graph[node].size(), sum = 0;
    for(int i = 0; i < lim; i++) {
        int neigh = graph[node][i];
        if(!viz[neigh]) {
            dfs(neigh);
            subTree[node] = (subTree[node] + subTree[neigh]) %  2;
            sum += subTree[neigh];
        }
    }
    sum += (n - subTree[node]) % 2;
    if(sum != 1) {
        printf("First\n");
        exit(0);
    }
}

int main (){
    int a, b;
    
    scanf("%d",&n);
    for(int i = 1; i < n; i++) {
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    printf("Second\n");
    return 0;
}

