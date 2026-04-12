#include <bits/stdc++.h>
#define re return
#define ll long long
#define ull unsigned ll
#define ld long double
#define f first
#define s second
#define pi acos(-1)
#define oo (ll)1e9
#define OO (ll)1e18
#define EPS 1e-7
#define FX(n) fixed<<setprecision(n)
#define mm(o,k) memset(o,k,sizeof o)
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int maxn=105;
int n,m;
char a[maxn][maxn];
int main()
{
    IO;
    cin >> n >> m;
    vector<bool> row(n,0),col(m,0);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin >> a[i][j];
    for(int i=0;i<n;++i){
        int cnt=0;
        for(int j=0;j<m;++j)
            cnt+=a[i][j]=='.';
        if(cnt==m)row[i]=true;
    }
    for(int i=0;i<m;++i){
        int cnt=0;
        for(int j=0;j<n;++j)
            cnt+=a[j][i]=='.';
        if(cnt==n)col[i]=true;
    }
    bool ok=false;
    for(int i=0;i<n;++i,((ok)?cout<<endl,ok=false:ok=ok))
        for(int j=0;j<m;++j)
            if(!row[i]&&!col[j])
                cout<<a[i][j],ok=true;
    re 0;
}