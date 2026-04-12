#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
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
#define oo 3003
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
int n;
int a[oo],mina=1e6;
int f[oo][oo];
void ReadInPut()
{
    n=read();
    F(i,1,n)a[i]=read();
}
int tinh(int i,int j)
{
	if(f[i][j]!=-1) return f[i][j];
	if(i>j)return 0;
    int res;
    if((i-1+n-j)%2)res=min(tinh(i+1,j)-a[i],tinh(i,j-1)-a[j]);
    else res=max(tinh(i+1,j)+a[i],tinh(i,j-1)+a[j]);
    f[i][j]=res;
    return res;
}
void Solve()
{
    reset(f,-1);
    cout<<tinh(1,n);
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
