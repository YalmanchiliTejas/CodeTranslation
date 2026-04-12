#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define FD(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define pii pair<int,int>
#define reset(x,y) memset(x, y,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EL putchar('\n');
#define mod 1000000007
#define oo 1000006
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
void write(int x)
{
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
string s;
int n[100005],d,f[10004][100][3];
void ReadInPut()
{
    cin>>s>>d;
    F(i,0,s.size()-1)n[i+1]=int(s[i]-48);
}
int tinh(int i,int j,int ok)
{
    //cout<<i<<" "<<j<<" "<<ok<<'\n';
    if(i==s.size()+1)return j==0&&ok<2;
    if(f[i][j][ok]!=-1)return f[i][j][ok];
    f[i][j][ok]=0;
    if(i>1&&j==0)f[i][j][ok]++;
    F(z,0,9)
    {
        if(i==1&&z==0)continue;
        if(ok==1||(ok==0&&z==n[i])||(ok==2))f[i][j][ok]=(f[i][j][ok]+tinh(i+1,(j+z)%d,ok))%mod;
        if(ok==0&&z<n[i])f[i][j][ok]=(f[i][j][ok]+tinh(i+1,(j+z)%d,1))%mod;
        if(ok==0&&z>n[i])f[i][j][ok]=(f[i][j][ok]+tinh(i+1,(j+z)%d,2))%mod;
    }
    return f[i][j][ok];
}
void Solve()
{
    reset(f,-1);
    cout<<tinh(1,0,0);
}
main()
{
//    freopen("t.INP","r",stdin);
  //  freopen(".OUT","w",stdout);
    int sotest=1;
    //cin>>sotest;
    for(int i=1;i<=sotest;i++)
    {
        ReadInPut();
        Solve();
    }
}
