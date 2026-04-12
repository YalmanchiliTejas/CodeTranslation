#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int g[10][10];

int main(int argc, char const *argv[])
{
    int n,m;scanf("%d %d",&n,&m);
    for (int i = 0; i < m; ++i)
    {
        int a,b;scanf("%d %d",&a,&b);
        a--,b--;
        g[a][b] = g[b][a] = 1;
    }
//    cout << g[0][1] << " " << g[1][0] << endl;
    vector<int> v(n-1);
    int ans = 0;
    iota(v.begin(),v.end(),1);
    do{
        vector<int> path;
        path.push_back(0);
        bool ok = true;
        for(int i = 0 ;i < n-1;i++)path.push_back(v[i]);
        for(int i = 0;i < n-1;i++){
            if(!g[path[i]][path[i+1]]){ok = false;break;}
        }
        if(ok){ans++;}
    }while(next_permutation(v.begin(),v.end()));

    printf("%lld\n", ans);
    return 0;
}