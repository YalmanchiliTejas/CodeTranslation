#include <stdio.h>
#include <stdlib.h>
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
struct P
{

    int x,y;

    bool operator<(const P &a)const{
       // if(y!=a.y)
       // return y>a.y;
       return x>a.x;
//        return z>a.z;
    }
};
vector<P> v[1010];

int a,b,c,o[2000000],i,k,d,n,m,e,dy[15]={0,0,-1,1,-1,1,-1,1},dx[15]={-1,1,0,0,1,1,-1,-1};
int l[3500005];

long long x,y,z[52],v1,v2;
//P u[100600];
int j[6000000];
queue<P> q,q1;
stack<int> s;
//queue<P> q;

//deque<int> d;
//'1'==49;
//'A'==65;
//'a'==97;
map<string, int > p;
string r,r1,r2;
//char r[1010];





//2147483647
int main()
{
    cin>>r;
    for(int t=1;t<r.size();t++)
        if(r[t-1]=='A'&&r[t]=='C')
        i=1;
    if(i) puts("Yes");
    else puts("No");

}
