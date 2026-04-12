#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b;++i)
#define fdto(i,a,b) for(int i=a; i>=b;--i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define ll long long
#define maxn 300009
#define maxm 100009
#define gb(i,j) ((i>>j)&1)
#define name "a"
#define endl '\n'
#define int ll

using namespace std;

const int mod=1e9+7;

int mu(int a, int b){
    if(b==0)return 1;
    int tg=mu(a,b/2);
    tg=(tg*tg)%mod;
    if(b%2)tg=(tg*a)%mod;
    return tg;
}
int p[2009],p1[2009];
int C(int a, int b){
    return p[a+b]*p1[a]%mod *p1[b] %mod;
}
int n,a,b,c,d,h[2009][2009],f[2009][2009],h1[2009][2009];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> a >> b >> c >> d;
    p[0]=1;
    fto(i,1,n*2)p[i]=p[i-1]*i%mod;
    fto(i,0,n*2)p1[i]=mu(p[i],mod-2);
    fto(i,0,n)
        fto(j,0,n)h[i][j]=C(i,j);
    fto(i,1,n){
        h1[i][1]=1;
        fto(j,2,d){
            if(j*i>n)break;
            h1[i][j]=(h1[i][j-1]*h[i][j*i-i])%mod;
        }
        fto(j,2,d){
            if(j*i>n)break;
            h1[i][j]=(h1[i][j]*p1[j])%mod;
        }
    }
    f[0][a-1]=1;
    for(int i=a; i<=b; ++i){
        for(int j=i*c; j<=i*d && j<=n;j+=i)
            for(int t=j; t<=n; ++t)
            if(f[t-j][i-1]){
                f[t][i]=(f[t][i]+f[t-j][i-1]*h[j][n-t]%mod * h1[i][j/i])%mod;
                //if(f[t][i]) cout << f[t-j][i-1]<<' '<< t <<' '<< j <<' '<< h[j][n-t]<<' '<< h1[i][j/i]<<endl;
            }
        //cout << i <<endl;
        //fto(j,0,n)cout << j <<' '<<f[j][i]<<endl;
        fto(j,0,n)f[j][i]=(f[j][i]+f[j][i-1])%mod;
    }
    cout << f[n][b];
    return 0;
}
