#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define each(it,v) for(auto &it : v)
#define mod 1000000007
#define All(v) (v).begin(),(v).end()
#define vi vector<int>
#define vl vector<long>
#define P pair<int,int>
#define Graph vector<vector<int>>
using namespace std;

vl a,p;

long f(long n,long x)
{
        if(n==0)
        {
                if(x<=0)return 0;
                else return 1;
        }else if(x<=1+a[n-1])
        {
                return f(n-1,x-1);
        }else
        {
                return p[n-1]+1+f(n-1,x-2-a[n-1]);
        }
}


main()
{
        long n,x; cin>>n>>x;
        
        a.resize(n); p.resize(n);
        a[0]=1; p[0]=1;
        FOR(i,1,n-1)
        {
                a[i]=a[i-1]*2+3;
                p[i]=p[i-1]*2+1;
        }

        cout<<f(n,x)<<endl;
}
