#include <iostream>
#include <algorithm>
using namespace std;

int g[10][10];
int main()
{
    int n, m; cin>>n>>m;
    while (m--) {
        int a, b; cin>>a>>b;
        --a, --b;
        g[a][b]=g[b][a]=1;
    }

    int a[n];
    for(int i=0; i<n; ++i) a[i]=i;

    int res=0;
    do {
        bool ok=true;
        for(int i=1; i<n; ++i) if (!g[a[i]][a[i-1]]) ok=false;
        if (ok) ++res;
    } while (next_permutation(a+1, a+n));
    cout<<res<<endl;
}
