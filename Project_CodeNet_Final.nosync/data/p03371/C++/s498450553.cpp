#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=1e6;
int a,b,c;
int x,y;
int ans;
int main()
{
   cin>>a>>b>>c;
   cin>>x>>y;
   if(a+b<=2*c)
     ans=a*x+b*y;
   else
   {
    if(x>y)
    {
        int num=x-y;
        ans+=y*2*c;
        if(a<=2*c)
        ans+=num*a;
       else
        ans+=num*2*c;
    }
    else
    {
        int num=y-x;
        ans+=x*2*c;
        if(b<=2*c)
        ans+=num*b;
       else
        ans+=num*2*c;
    }
   }
   cout<<ans<<endl;
    return 0;
}