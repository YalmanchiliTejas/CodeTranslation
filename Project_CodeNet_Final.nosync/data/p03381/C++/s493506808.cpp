#include <bits/stdc++.h>
using namespace std;


struct P
{
    int x,y,z;

    /*bool operator<(const P &a)const{
        if(x!=a.x)
        return x>a.x;
              return y>a.y;
    }*/
};

vector<int> v[2];
//bitset<4001000> b;
int a,c,i,b,k,n,d,e,m;//dy[15]={0,1,0,-1,-1,1,-1,1},dx[15]={1,0,-1,0,1,1,-1,-1};//
int l[2252];

int o[251111];
int dx[10]={0,1,0,-1,1,1,-1,-1},dy[10]={-1,0,1,0,1,-1,1,-1},dz[10]={0,0,0,0,1,-1};


long long x,y,mod=1000000007;
long long z;
int j[330][111];
P u[221110];
stack<int> s;

//set<int> s;
queue<int > q;

//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int> p[2];
//list<int> l;
//string r1,r;
char r[115][111];
//deque<int> de;

//20921
bool as(P a,P b)
{
    return a.x<b.x;
}


int main()
{
    scanf("%d",&a);
    for(int t=1;t<=a;u[t].y=t,t++)
        scanf("%d",&u[t].x);
    sort(u+1,u+1+a,as);
    for(int t=1;t<=a;t++)
        if(t*2<=a)
    {
        o[u[t].y]=u[a/2+1].x;
    }
    else o[u[t].y]=u[a/2].x;
    for(int t=1;t<=a;t++)
        printf("%d\n",o[t]);
}
