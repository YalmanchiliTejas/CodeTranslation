#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <cstdio>
#include <float.h>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
       
using namespace std;
       
#define endl '\n'
#define MOD 1000000007
#define INF 1ll<<30
 
// #define MAX 100010
 
#define eps 1e-11
#define bit_max 1ll<<32
#define _USE_MATH_DEFINES


int g[100][100];

bool vis[10];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    // #endif
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a][b]=1;
        g[b][a]=1;
    }
    int path[n];
    for(int i=0;i<n;i++)
    {
        path[i]=i;
    }
    int ans = 0;
    do
    {
        if(path[0]!=0)
            continue;
        int i;
        for(i=0;i<n-1;i++)
        {
            if(g[path[i]][path[i+1]]==0)
                break;
        }
        if(i==n-1)
            ans++;
    }
    while(next_permutation(path,path+n));
    cout<<ans<<endl;
    return 0;
}