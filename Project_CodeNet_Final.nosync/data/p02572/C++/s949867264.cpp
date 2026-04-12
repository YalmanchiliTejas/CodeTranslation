#include <bits/stdc++.h>
using namespace std;
int N;
long P=0,S=0,m=1e9+7;
main()
{
    cin>>N;
    long S=0;
    for(int i=0;i<N;++i){
        long a;cin>>a;
        P=(P+a*S)%m;
        S=(S+a)%m;
    }
    cout<<P<<endl;
}