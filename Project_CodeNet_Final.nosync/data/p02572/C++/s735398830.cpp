#include <bits/stdc++.h>
#include <vector>
#include<math.h>
#include<string.h>
using namespace std;
#define MAX 1005
#define MOD 1000000007
#define INF 1000000000000000000
#define EPS 0.0000000001
#define CHAINS 18
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
int main()
{
    int n,i;
    scanf("%d",&n);
    long long A[n];
    long long sum=0,ans=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&A[i]);
        ans=(ans+sum*A[i])%MOD;
        sum=(sum+A[i])%MOD;
    }
    printf("%lld",ans);
    return 0;
}
