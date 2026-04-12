#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
#define f first
#define s second
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)998244353;
const double eps=1e-9;
long long seen[100005],v[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,x,m,sum=0;
    cin>>n>>x>>m;
    if(n<=100000){
        sum=v[1]=x;
        for(int i=2;i<=n;i++)
            v[i]=(v[i-1]*v[i-1])%m,
            sum+=v[i];
        return cout<<sum,0;
    }
    int ctr=1,cycleBegin,cycleEnd;
    sum=v[1]=x;
    for(int i=2;;i++)
    {
        v[i]=(v[i-1]*v[i-1])%m;
        cycleBegin=seen[v[i]];
        cycleEnd=i-1;
        if(seen[v[i]])
            break;
        seen[v[i]]=i;
        sum+=v[i];
        ctr++;
    }
    long long cycleSum=0;
    for(int i=cycleBegin;i<=cycleEnd;i++)
        cycleSum+=v[i];
    long long rem=n-ctr;
    sum+=rem/(cycleEnd-cycleBegin+1)*cycleSum;
    rem%=cycleEnd-cycleBegin+1;
    for(int i=cycleBegin;i<cycleBegin+rem;i++)
        sum+=v[i];
    cout<<sum;
    return 0;
}
