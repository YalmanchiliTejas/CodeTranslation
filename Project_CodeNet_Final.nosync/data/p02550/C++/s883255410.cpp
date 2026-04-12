#include <bits/stdc++.h>
/// TONI BO$$ was here
/// #MLC

using namespace std;
int r[100001];
vector <long long> v;
int main()
{
    int i,j;
    long long n,x,m;
    scanf("%lld%lld%lld",&n,&x,&m);
    r[x]=1;
    v.push_back(x);
    for(i=2; i<=n; i++)
    {
        x=(x*x)%m;
        if(r[x])
            break;
        r[x]=1;
        v.push_back(x);
    }
    if(i>n || r[0]==1)
    {
        long long s=0;
        for(auto it : v)
            s+=it;
        printf("%lld",s);
        return 0;
    }
    long long s=0,s2=0,s3=0;
    for(i=0; i<v.size() && v[i]!=x; i++) s3+=v[i];
    n-=i;
    for(j=i; j<i+n%(v.size()-i); j++)
        s2+=v[j];
    for(j=i; j<v.size(); j++) s+=v[j];
    printf("%lld",s*(n/(v.size()-i))+s2+s3);

    return 0;
}
///492443256042078
///492443256176507
