#include <bits/stdc++.h>
using namespace std;
int N;
long P=0,m=1e9+7;
main()
{
    cin>>N;
    long s=0;
    for(int i=0;i<N;++i){
        long a;
        cin>>a;
        P=(P+a*s)%m;
        s=(s+a)%m;
    }
    cout<<P<<endl;
}