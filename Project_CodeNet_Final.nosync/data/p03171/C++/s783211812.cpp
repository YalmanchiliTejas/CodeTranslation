#include<iostream>
using namespace std;

long long int dp[3001][3001][2];

long long int play(long int a[],int start,int end,int chance,long long int x,long long int y)
{
    if(start==end)
    {
        if(chance)
        {
            y+=a[start];
        }else
        {
            x+=a[start];
        }
        return x-y;
    }
    long long int t1,t2;
    if(chance)
    {
        if(!dp[start+1][end][0])
        {
            dp[start+1][end][0]=play(a,start+1,end,0,x,y+a[start])-x+y+a[start];
        }
        if(!dp[start][end-1][0])
        {
            dp[start][end-1][0]=play(a,start,end-1,0,x,y+a[end])-x+y+a[end];
        }
        t1=dp[start+1][end][0]+x-y-a[start];
        t2=dp[start][end-1][0]+x-y-a[end];
        return min(t1,t2);
    }
    if(!dp[start+1][end][1])
    {
        dp[start+1][end][1]=play(a,start+1,end,1,x+a[start],y)-x-a[start]+y;
    }
    if(!dp[start][end-1][1])
    {
        dp[start][end-1][1]=play(a,start,end-1,1,x+a[end],y)-x-a[end]+y;
    }
    t1=dp[start+1][end][1]+x+a[start]-y;
    t2=dp[start][end-1][1]+x+a[end]-y;
    return max(t1,t2);
}

int main()
{
    int n;
    cin>>n;
    long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<play(a,0,n-1,0,0,0);
}
