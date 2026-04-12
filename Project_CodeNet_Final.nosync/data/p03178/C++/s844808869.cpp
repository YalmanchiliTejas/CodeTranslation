#include <bits/stdc++.h>
 
using namespace std;
long long x,p[10001][100][2];
vector <long long> d;
string a;
long long cal(long long i,long long s,bool t)
{
    if (i==d.size())
        return !s;
    if (p[i][s][t]>-1)
        return p[i][s][t];
    long long tp=0,lim=(t)?d[i]:9;
    for (long long dg=0; dg<=lim; dg++)
    {
        bool nt=(dg<lim)?0:t;
        tp=(tp+cal(i+1,(s+dg)%x,nt))%1000000007;
    }
    return p[i][s][t]=tp;
}
long long ans(string num)
{
    memset(p,-1,sizeof(p));
    d.clear();
    for (int i=0;i<num.size();i++)
        d.push_back(num[i]-'0');
    return cal(0,0,1);
}
 
main()
{
    cin>>a>>x;
    cout<<(ans(a)+1000000006)%1000000007;
}