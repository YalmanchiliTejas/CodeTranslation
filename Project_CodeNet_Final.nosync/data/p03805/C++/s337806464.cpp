#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <bitset>
#include <time.h>
#include <set>
#include <algorithm>
#define ll long long
#define Inf 123372036854775806ll
using namespace std;

vector<int> edges[10];
int dfs(int u,int mask,int N) {
    mask |= (1<<(u-1));
    if (mask == (1<<N)-1) {
        return 1;
    }
    int ans=0;
    for(int i=0;i<edges[u].size();i++) {
        int v=edges[u][i];
        if ((mask>>(v-1))&1)
            continue;
        ans+=dfs(v,mask,N);
    }
    return ans;
    
}

int main() {
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=M;i++) {
        int a,b;
        cin>>a>>b;
        
        edges[a].push_back(b);
        edges[b].push_back(a);
        
    }
    
    cout << dfs(1,0,N) << endl;
    
}