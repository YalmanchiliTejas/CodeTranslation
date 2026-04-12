#include<bits/stdc++.h>
using namespace std;
const int MAXN = (1<<8)+5;
long long d[MAXN][8];
int n,m;
vector<int>E[10];
int mp[10][10];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--,b--;
        mp[a][b]=1;
        mp[b][a]=1;
    }
    d[1][0]=1;
    for(int i=1;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                bool ok = (i&(1<<k));
                if(mp[j][k]&&!ok){
                    int next = i|(1<<k);
                    d[next][k] = d[next][k] + d[i][j];
                }
            }
        }
    }
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum+=d[(1<<n)-1][i];
    }
    cout<<sum<<endl;
}
