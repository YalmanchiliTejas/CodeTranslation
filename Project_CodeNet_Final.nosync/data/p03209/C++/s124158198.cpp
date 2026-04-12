#include<stdio.h>
#include<string.h>
#include<utility>
#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
 
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

long long int pa(int rank,long long int si,long long int *pat,long long int *sum)
{
    if(rank==0&&si==0)return 0;
    else if(rank==0&& si==1)return 1;
    else if(si==0 || si==1)return 0;
    else if(si<=*(sum+rank-1)+1)return pa(rank-1,si-1,pat,sum);
    else if(si==*(sum+rank-1)+2)return *(pat+rank-1)+1;
    else if(si==*(sum+rank))return *(pat+rank);
    else return *(pat+rank-1)+pa(rank-1,si-2-*(sum+rank-1),pat,sum)+1;
}

int main()
{
    int n;
    long long int x;
    scanf("%d %lld",&n,&x);
    long long int pat[55]={};
    long long int sum[55]={};
    pat[0]=1;
    sum[0]=1;
    REP(i,50)
    {
        pat[i+1]=pat[i]*2+1;
        sum[i+1]=sum[i]*2+3;
    }
    long long int ans=pa(n,x,pat,sum);
    printf("%lld\n",ans);
    return 0;
}