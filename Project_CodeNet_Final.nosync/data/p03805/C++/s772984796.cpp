#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

int G[10][10];
int a[10];

signed main()
{
    int N,M; cin>>N>>M;
    REP(i,M){
        int a,b; cin>>a>>b;
        a--; b--;
        G[a][b]=G[b][a]=1;
    }

    int ans=0;
    REP(i,N) a[i]=i;
    do{ 
        bool ok=true;
        REP(i,N-1) ok&=G[a[i]][a[i+1]];
        if(ok) ans++;
    }while(next_permutation(a+1,a+N));
    cout<<ans<<endl;

}