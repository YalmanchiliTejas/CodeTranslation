#include<bits/stdc++.h>
using namespace std;

int const N=3e3+5, M=1e5+5, OO = 0x3f3f3f3f;

int n;
int arr[N];

long long mem[N][N][2];
long long solve(int s, int e, int last)
{
    if(s>e)
        return 0;
    if(mem[s][e][last]!=-1)
        return mem[s][e][last];
    long long ret=0;
    if(last)
        ret=max(solve(s+1,e,0)+arr[s],solve(s,e-1,0)+arr[e]);
    else
        ret=min(solve(s+1,e,1)-arr[s],solve(s,e-1,1)-arr[e]);
    return mem[s][e][last]=ret;
}


int main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",arr+i);
    memset(mem, -1, sizeof mem);
    printf("%lld\n",solve(0,n-1,1));


}
