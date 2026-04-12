#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<cmath>
#include<set>
#include<stack>
#define ll long long
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))
#define cls(name,x) memset(name,x,sizeof(name))
using namespace std;
const int inf=1<<28;
const int maxn=20010;
const int maxm=20010;
const int mod=1e9+7;
const double pi=acos(-1.0);
int n;
int main()
{
    //freopen("in.txt","r",stdin);
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if((a*100+b*10+c)%4==0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
