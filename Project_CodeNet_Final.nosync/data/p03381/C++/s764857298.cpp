#include <bits/stdc++.h>
using namespace std;

int n,opt,c[400001][2],sz[400001],f[400001],num[400001],root,len,v[400001];
int a[400001];
void add(int x,int fa)
{
    ++len;
    v[len]=x;
    sz[len]=1;
    num[len]=1;
    f[len]=fa;
    if(x<v[fa])
    c[fa][0]=len;
    else
    c[fa][1]=len;
    c[len][0]=c[len][1]=0;
}
void pushup(int x)
{
    sz[x]=sz[c[x][0]]+sz[c[x][1]]+num[x];	
}
int findip(int d)
{
    int x=root;	
    while(v[x]!=d)
    {
//		cout<<c[x][0]<<" "<<c[x][1]<<endl;
        if(d<v[x])
        {
            if(c[x][0]==0)
            break;
            else
            x=c[x][0];
        }
        else
        {
            if(c[x][1]==0)
            break;
            else
            x=c[x][1];
        }
    }
    return x;
}
void rotate(int x)
{
    int y=f[x],z=f[y],k=c[y][1]==x,w=c[x][!k];
    if(y!=root)
    c[z][c[z][1]==y]=x;
    c[x][!k]=y;
    c[y][k]=w;
    if(w)
    f[w]=y;
    f[y]=x;
    f[x]=z;
    pushup(y);
}
void splay(int x,int rt)
{
    while(f[x]!=rt)
    {
        int y=f[x],z=f[y];
        if(f[y]!=rt)
        {
            if(c[z][0]==y ^ c[y][0]==x)
            rotate(x);
            else
            rotate(y);
        }
        rotate(x);
        if(rt==0)
        root=x;
    }
    pushup(x);
}
void ins(int x)
{
    if(root==0)
    {
        add(x,0);
        root=len;
        return;
    }
    int y=findip(x);
    if(v[y]==x)
    {
        num[y]++;
        pushup(y);
        splay(y,0);
    }
    else
    {
        add(x,y);
        pushup(y);
        splay(len,0);
    }
}
void del(int x)
{
    int y=findip(x);
    splay(y,0);
    if(num[y]>1)
    {
        num[y]--;
        pushup(y);
        return;
    }
    if(c[y][0]==0&&c[y][1]==0)
    {
        root=0;
        len=0;
    }
    else if(c[y][0]==0&&c[y][1]!=0)
    {
        root=c[y][1];
        f[root]=0;
    }
    else if(c[y][0]!=0&&c[y][1]==0)
    {
        root=c[y][0];
        f[root]=0;
    }
    else
    {
        int z=c[y][0];
        while(c[z][1])
        z=c[z][1];
        splay(z,y);
        int r=c[y][1];
        c[z][1]=r;
        f[r]=z;
        root=z;
        f[root]=0;
        pushup(z);
    }
}
int findshuzi(int k)
{
    int x=root;
    while(1)
    {
        if(k<=sz[c[x][0]])
        x=c[x][0];
        else if(k>sz[c[x][0]]+num[x])
        {
            k-=sz[c[x][0]]+num[x];
            x=c[x][1];
        }
        else
        break;
//		cout<<x<<endl;
    }
    splay(x,0);
    return v[x];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&a[i]);
    	ins(a[i]);
	}
    
    for(int i=1;i<=n;i++)
    {
    	del(a[i]);
    	printf("%d\n",findshuzi(n/2));
    	ins(a[i]);
	}
    return 0;
}