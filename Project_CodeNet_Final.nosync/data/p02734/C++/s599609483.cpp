#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int N=3010;
ll f[N][N][2];
int a[N];
int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)f[i][0][0]=1;
    // f[0][0][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            (f[i][j][0]+=f[i-1][j][0])%=mod;
            if(j>=a[i]){
                (f[i][j][0]+=f[i-1][j-a[i]][0])%=mod;
            }
        }
    }
    ll sum=0;
    for(int i=1;i<=n;i++)(sum+=f[i][s][0])%=mod;
    cout<<sum<<endl;
}