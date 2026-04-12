#import<bits/stdc++.h>
using namespace std;
pair<long,long>p[1<<18];
long I,A,n,r,b,d,t,i;
main()
{
    d=I=b=1e9;
    for(cin>>n; i<n; i++)
    {
        cin>>p[i].first>>p[i].second;
        if(p[i].first>p[i].second)
            swap(p[i].first,p[i].second);
        I=min(I,p[i].first),A=max(A,p[i].second),r=max(r,p[i].first),b=min(b,p[i].second);
    }
    i=~0;
    sort(p,p+n);
    t=(r-I)*(A-b);
    b=p[1+i].first,r=p[n+i].first;
    for(t=min(t,(A-I)*(r-b)); ++i<n; t=min(t,(A-I)*(r-b)))
        b=min(min(p[i].second,i-n+1?p[1+i].first:A),d),d=min(d,p[i].second),r=max(r,p[i].second);
    cout<<t;
}
