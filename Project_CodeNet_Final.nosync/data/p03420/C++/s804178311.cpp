#include <bits/stdc++.h>
using namespace std;
struct P
{
    //string r;
    int x,y,z;

    bool operator<(const P &a)const{
       // if(y!=a.y)
       // return y>a.y;
       return x<a.x;
//        return z>a.z;
    }
};

vector<int> v[155];
//bitset<4001000> b;
int a,c,i,b,k,d,n,m;
long long e[100100];//dy[15]={0,1,0,-1,-1,1,-1,1},dx[15]={1,0,-1,0,1,1,-1,-1};//
long long l[1201010];
int o[1200150];
int dx[10]={0,1,0,-1},dy[10]={1,0,-1,0},dz[10]={0,0,0,0,1,-1};

long long x,y,z[200100],mod=1000000007;
P u[11];
long long j[200011];

stack<int> s;
queue<int> q;

//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int > p;
//list<int> l;
//string r[111],r2;
char r[510][555];


bool as(P a,P b)
{
   // if(a.x!=b.x)
        return a.x<b.x;
    //return a.y>b.y;
}



int main()
{
    scanf("%d %d",&a,&b);
    if(b)
    for(int t=b+1;t<=a;t++)
    {
        x+=max((long long)0,(long long)(t-1-b+1)*(a/t));
        x+=max(0,a%t-b+1);
    }
    else x=(long long)a*a;
    printf("%lld",x);
}
