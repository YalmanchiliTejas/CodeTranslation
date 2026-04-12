#include <iostream>
#include <algorithm>
using namespace std;
long long n,act,r,add,urm,sol,v[53];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>v[i];
    bool ok=true;
    while(ok==true)
    {
        sort(v+1,v+n+1);
        ok=false;
        add=0;
        if(v[n]>n-1)
        {
            ok=true;
            r=v[n]%n;
            add=v[n]/n;
            for(int i=1;i<n;++i) v[i]+=add;
            v[n]=r;
        }
        sol+=add;
    }
    cout<<sol;
    return 0;
}
