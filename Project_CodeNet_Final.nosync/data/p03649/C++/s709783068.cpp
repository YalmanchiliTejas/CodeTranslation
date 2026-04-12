#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>
#include <string.h>
#define inf 0x7fffffff
using namespace std;
struct I
{
    int x,y;
};


int a,b,c,k,n,m,i,d,e[4010][4005],o[410200],l[212000],dx[20]={1,-1},dy[20]={0,0,1,-1},dz[20]={1,-1};
long long x,y[200],z[200];
//map <string,int> m;
int j[1060][20];

stack<int> s;
char r1[5500];
//deque<int> d;
struct P
{
    int x,y;
    /*bool operator<(const P &a)const
    {

        return max(x,-x)<=max(a.x,-a.x);
    }*/
};
double u;
//P u[500000];
vector <int> v[211010];
queue<int> q;
string r;

//A==65
//Z==90

//a==97

bool sdf(P a,P b)
{
    return a.x<b.x;
}



int main()
{
    scanf("%lld",&x);
    for(long long t=1;t<=x;t++)
    {
        scanf("%lld",&z[t]);
    }
    long long k=0;
    for(;;)
    {
        int i=0;
        for(long long t=1;t<=x;t++)
        {
            if(z[t]+k-y[t]>=x)
            {
                long long a=(z[t]+k-y[t])%x;//z[t]
                long long b=(z[t]+k-y[t])/x;//k
                k+=b;
                y[t]+=b;
                z[t]=a-k+y[t];


                i=1;
            }
        }

        if(!i) break;
    }
printf("%lld\n",k);
}
