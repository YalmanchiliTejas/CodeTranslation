#include <bits/stdc++.h>
using namespace std;
//using lint = long long;

struct P
{
    int x,y;

    bool operator<(const P &a)const{
        if(x!=a.x)
              return x>a.x;
        return y>a.y;
    }

};

vector<int> v[1],v1;

//bitset<4001000> b;
int i,n,d,m,k,a,b,c,h;

int o[3111];
long long l[3111][3111];
int j[1];
int e;


//int dx[10]={2,2,-2,-2,1,1,-1,-1},dy[10]={1,-1,1,-1,2,-2,2,-2};

int dx[10]={0,1,0,-1,1,1,-1,-1},dy[10]={1,0,-1,0,1,-1,1,-1},dz[10]={0,0,0,0,1,-1};
long long mod=1000000007,mod2=1000000009,mod3=2017;
long long x,z,y;
double pi=3.14159265;
P u[1];
stack<int> s;
//set<int> s[222][22];
//priority_queue<P> q;
queue<int> q;
//2147483647
//'1'==49;
//'A'==65;
//'a'==97;
//unordered_
//map<int,int> p;
/*
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<long long, int, custom_hash> safe_map;
*/
//list<int> l;

//string r,r1;
char r[2222][1111];
//deque<int> de;
//srand((int)time(NULL));
/*bool as(P a,P b)
{
    if(a.x!=b.x)
    return a.x<b.x;
    return a.y<b.y;
}*/



bool as(P a,P b)
{
    if(a.x!=b.x)
        return a.x<b.x;
    return a.y<b.y;

}


long long f(int n,int m)
{
    if(n>m) return 0;
    if(l[n][m]>=0) return l[n][m];
    if((m-n+1)%2==a%2) return l[n][m]=max(f(n+1,m)+o[n],f(n,m-1)+o[m]);
    return l[n][m]=min(f(n+1,m),f(n,m-1));
}

int main()
{
    memset(l,-1,sizeof(l));
    scanf("%d",&a);
    for(int t=1;t<=a;x+=o[t],t++)
        scanf("%d",&o[t]);
    printf("%lld",2*f(1,a)-x);
}



