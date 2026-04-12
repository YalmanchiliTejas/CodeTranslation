#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,k;
    scanf("%d%d",&n,&k);
    if (k==0)
    {
        cout<<(long long)n*n<<endl;
        return 0;
    }
    int i;
    long long ans=0;
    for (i=1;i<=n;i++)
    {
        //b = i
        if (i<=k) continue;
        int t=n/i;
        ans+=(long long)(i-k)*t;
        ans+=max(n%i-k+1,0);
    }
    cout<<ans<<endl;
    return 0;
} 
