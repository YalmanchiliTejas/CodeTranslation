#include <bits/stdc++.h>
#include <vector>
#include<math.h>
#include<string.h>
using namespace std;
#define MAX 200005
#define MOD 1000000007
#define INF 1000000000000000000
#define EPS 0.0000000001
#define CHAINS 18
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
vector<long long> A,sum;
int indices[MAX];
int main()
{
    int m;
    long long i,x,n,ans=0;
    scanf("%lld %lld %d",&n,&x,&m);
    A.push_back(x);
    indices[(int)x]=1;
    ans=ans+x;
    for(i=1;i<n;i++)
    {
        x=x*x;
        x=x%m;
        //printf("x=%lld\n",x);
        if(indices[(int) x]) break;
        A.push_back(x);
        indices[(int)x]=i+1;
        ans=ans+x;
    }
    if(i==n)
    {
        printf("%lld",ans);
        return 0;
    }
    long long rem=n-i;
    for(i=indices[(int) x]-1;i<A.size();i++)
    {
        sum.push_back(A[i]);
    }
    for(i=1;i<sum.size();i++)
    {
        sum[i]=sum[i]+sum[i-1];
    }
    long long dd=sum.size();
    dd=rem/dd;
    ans=ans+dd*sum[sum.size()-1];
    dd=sum.size();
    dd=rem%dd;
    if(dd>0)
    {
        ans=ans+sum[(int)(dd-1)];
    }
    printf("%lld",ans);
    return 0;
}
