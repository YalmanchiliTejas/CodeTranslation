#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cstdlib>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
#include<vector>
#include<cmath>
#include<string>
#include<bitset>
#define lmid l,mid,rt<<1
#define rmid mid+1,r,rt<<1|1
#define ll long long
using namespace std;
int main()
{
     int x,y,z;
     scanf("%d%d%d",&x,&y,&z);
     for(int i=1;;i++)
     {
          int sum=i*y+(i-1)*z+2*z;
          if(sum>x)
          {
               printf("%d\n",i-1);
               break;
          }
     }
     return 0;
}
