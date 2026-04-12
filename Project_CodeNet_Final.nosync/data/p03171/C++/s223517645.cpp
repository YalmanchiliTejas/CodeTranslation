#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long>a;
long long mem[3000][3000];
long long dp(int i,int j)
{
    if(i>j)
        return 0;
    if(mem[i][j]!=-1)
        return mem[i][j];

    if((n-(i+j))%2!=0)
    mem[i][j]=max(a[i]+dp(i+1,j),a[j]+dp(i,j-1));
    else
    mem[i][j]=min(dp(i+1,j)-a[i],dp(i,j-1)-a[j]);
    return mem[i][j];
}
int main()
{
    memset(mem,-1,sizeof(mem));
    cin>>n;
    a.resize(n);
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<dp(0,n-1);
    return 0;
}
