#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int main(void)
{
    priority_queue<long long>q;
    long long i,n,num,x,limit,step=0;
    scanf("%lld",&n);limit=n-1;
    for(i=1;i<=n;++i)
    {
        scanf("%lld",&x);q.push(x);
    }
    while(q.top()>limit)
    {
        x=q.top();q.pop();
    	num=ceil((x-limit)/(n+1.00));
    	q.push(x-num*(n+1));
    	limit-=num;step+=num;
    }
    printf("%lld\n",step);
    return 0;
}