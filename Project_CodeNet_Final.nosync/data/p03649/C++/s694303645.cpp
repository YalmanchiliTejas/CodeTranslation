#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<time.h>
#include<math.h>
#include<memory>
#include<vector>
#include<bitset>
#include<fstream>
#include<stdio.h>
#include<utility>
#include<sstream>
#include<string.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
long long ans[55];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    int i;
    for (i=0;i<n;i++)
    {
        cin>>ans[i];
    }
    long long anses=0;
    for (;;)
    {
        long long t=0;
        long long sum=0;
        for (i=0;i<n;i++)
        {
            t=ans[i]/n;
            ans[i]%=n;
            ans[i]-=t;
            sum+=t;
        }
        if (sum==0) break;
        for (i=0;i<n;i++)
        {
            ans[i]+=sum;
        }
        anses+=sum;
    }
    cout<<anses<<endl;
    return 0;
} 
