#include <bits/stdc++.h>
using namespace std;
struct P
{
    //string r;
    int x;

    int y,z;
    //string r;
    bool operator<(const P &a)const{
       // if(y!=a.y)
       // return y>a.y;
       return x>a.x;
//        return z>a.z;
    }
};
struct S
{
    int x,y;
};
vector<P> v[100333];
//bitset<4001000> bit;
int a,c,i,b,k,d,n,m,e=1987654321;//dy[15]={0,1,0,-1,-1,1,-1,1},dx[15]={1,0,-1,0,1,1,-1,-1};//
int l[200200];
int o[152202];
long long j[5][200100];
int dx[10]={0,1,0,-1},dy[10]={1,0,-1,0},dz[10]={0,0,0,0,1,-1};

long long x,y,z[5][100100],mod=1000000007;
P u[2222];
//int j[31][11111];

stack<S> s;
queue<int> q;


//deque<int> de;
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<string,int > p;
//list<int> l;
string r,r1,r2;
//char r[33][33];

bool as(int a,int b)
{
    return a>b;
}

long long f(int i,int n)
{
    if(l[i]==n) return 1;
    if(z[i][n]) return z[i][n];
    long long x=0;
    for(int h=0;h<v[n].size();h++)
    {
        //printf("@%d %d %d %d %d\n",n,v[n][h].x,j[i][n],j[i][v[n][h].x],v[n][h].y);
        if(j[i][n]==j[i][v[n][h].x]+v[n][h].y)
        {

            x+=f(i,v[n][h].x),x%=mod;
        }
    }
    return z[i][n]=x;
}

int main()
{
    //memset(z,-1,sizeof(z));
    scanf("%d %d %d %d",&a,&b,&l[1],&l[2]);
    for(int t=1;t<=b;t++)
    {
        //n=t;
        //m=t+1;
        //i=1;
        scanf("%d %d %d",&n,&m,&i);
        v[n].push_back({m,i});
        v[m].push_back({n,i});
    }
    memset(j,-1,sizeof(j));
    for(int u=1;u<=2;u++)
    {
        j[u][l[u]]=0;
        q.push(l[u]);
        for(;q.size();q.pop())
        for(int h=0;h<v[q.front()].size();h++)
        if(j[u][v[q.front()][h].x]<0||j[u][v[q.front()][h].x]>j[u][q.front()]+v[q.front()][h].y)
        {
            j[u][v[q.front()][h].x]=j[u][q.front()]+v[q.front()][h].y;
            q.push(v[q.front()][h].x);
        }
    }
    y=f(1,l[2]);
    x=y*y%mod;
    for(int t=1;t<=a;t++)
        if(j[1][t]==j[2][t]&&j[2][t]*2==j[1][l[2]])
        //if(t!=l[1]&&t!=l[2])
        x-=f(1,t)*f(1,t)%mod*f(2,t)%mod*f(2,t)%mod,x+=mod,x%=mod;
    for(int t=1;t<=a;t++)
        for(int h=0;h<v[t].size();h++)
        //if(t>v[t][h].x)
        if(v[t][h].y+j[1][t]+j[2][v[t][h].x]==j[1][l[2]]&&max(j[1][t],j[2][v[t][h].x])<min(j[1][t],j[2][v[t][h].x])+v[t][h].y)
            x-=f(1,t)*f(1,t)%mod*f(2,v[t][h].x)%mod*f(2,v[t][h].x)%mod,x+=mod,x%=mod;
    //for(int t=1;t<=a;t++)
    printf("%lld ",x);
}
