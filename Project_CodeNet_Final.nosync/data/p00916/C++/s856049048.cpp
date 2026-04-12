// by team3
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <climits>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <complex>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;

const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;
const int Maxn=105;
const int dx[4]={0,-1,1,0};
const int dy[4]={-1,0,0,1};

int N,Cntx,Cnty;
int X[Maxn],Y[Maxn],Idx[Maxn],Idy[Maxn];
long long Map[Maxn][Maxn];
bool f[Maxn][Maxn];

int Cmpx(const int &i,const int &j)
{
    return X[i]<X[j];
}

int Cmpy(const int &i,const int &j)
{
    return Y[i]<Y[j];
}

void dfs(int x,int y)
{
    f[x][y]=1;
    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||nx>Cntx) continue;
        if(ny<0||ny>Cnty) continue;
        if(Map[x][y]!=Map[nx][ny]) continue;
        if(!f[nx][ny]) dfs(nx,ny);
    }
}

int main()
{
    while(scanf("%d",&N)!=EOF&&N!=0)
    {
        for(int i=0;i<N;++i) scanf("%d%d%d%d",&X[i],&Y[i+N],&X[i+N],&Y[i]);
        for(int i=0;i<2*N;++i) Idx[i]=Idy[i]=i;
        sort(Idx,Idx+2*N,Cmpx);
        Cntx=0,Cnty=0;
        int last;
        for(int i=0;i<2*N;++i)
        {
            if(i==0) ++Cntx,last=X[Idx[0]];
            else if(X[Idx[i]]!=last) ++Cntx,last=X[Idx[i]];
            X[Idx[i]]=Cntx;
        }
        sort(Idy,Idy+2*N,Cmpy);
        for(int i=0;i<2*N;++i)
        {
            if(i==0) ++Cnty,last=Y[Idy[0]];
            else if(Y[Idy[i]]!=last) ++Cnty,last=Y[Idy[i]];
            Y[Idy[i]]=Cnty;
        }
        for(int i=0;i<=Cntx;++i)
            for(int j=0;j<=Cnty;++j)
                Map[i][j]=0;
        // rep(i,N) cout << X[i] << " " << X[N+i] << " ";
        // cout << endl;
        // rep(i,N) cout << Y[i] << " " << Y[N+i] << " ";
        // cout << endl;
        for(int i=0;i<N;++i)
            for(int j=X[i];j<X[i+N];++j)
                    for(int k=Y[i];k<Y[i+N];++k)
                        Map[j][k]|=(1ll<<i);
        // For(i,0,Cntx) {
        //     For(j,0,Cnty) cout << Map[i][j] << " ";
        //     cout << endl;
        // }
        for(int i=0;i<=Cntx;++i)
            for(int j=0;j<=Cnty;++j)
                    f[i][j]=0;
        int Ans=0;
        for(int i=0;i<=Cntx;++i)
            for(int j=0;j<=Cnty;++j)
                if(!f[i][j])
                {
                    dfs(i,j);
                    ++Ans;
                }
        printf("%d\n",Ans);
    }
    return 0;
}