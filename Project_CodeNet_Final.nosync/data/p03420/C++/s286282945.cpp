#include <iostream>
using namespace std;
#include<string.h>
#include<set>
#include<stdlib.h>
#include<map>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include <cstdio>
#include <cstdlib>
#include<stack>
#include<vector>
#include<cstdlib>
const int MAX=1e5+10;
long long n,m;
int a[MAX];
int main()
{
    cin>>n>>m;
    long long sum=0;
    if(m==0)
    {
        cout<<n*n<<endl;
        return 0;
    }
    for(int i=m+1;i<=n;i++)
    {
        int t=n/i;
        sum+=t*(i-m);
        int t1=n%i;
        //cout<<t1<<endl;
        if(t1>=m)
            sum+=t1-m+1;
        //cout<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}

