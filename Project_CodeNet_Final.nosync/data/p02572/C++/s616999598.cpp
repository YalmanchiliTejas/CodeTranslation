#include <bits/stdc++.h>
using namespace std;
int N;
long ans=0,m=1e9+7;
main()
{
    cin>>N;
    long long s=0;
    for(int i=0;i<N;++i){
        long a;
        cin>>a;
        ans=(ans+a*s)%m;
        s=(s+a)%m;
    }
    cout<<ans<<endl;
}