#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10;
vector<int> vc[M];
int dfs(int pos , int pre) {
    int len = vc[pos].size();
    int res = 0;
    for(int i = 0 ; i < len ; i++) {
        int v = vc[pos][i];
        if(v != pre) {
            res += dfs(v , pos);
        }
    }
    if(res >= 2) {
        printf("First\n");
        exit(0);
    }
    else if(res == 0) return 1;
    else return 0;
}
int main() {
    int n , u , v;
    scanf("%d" , &n);
    for(int i = 1 ; i < n ; i++) {
        scanf("%d%d" , &u , &v);
        vc[u].push_back(v);
        vc[v].push_back(u);
    }
    int ans = dfs(1 , 0);
    if(ans)
        printf("First\n");
    else
        printf("Second\n");
    return 0;
}