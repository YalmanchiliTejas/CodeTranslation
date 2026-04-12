#include<bits/stdc++.h>
using namespace std;
main()
{
    string a;
    cin>>a;
    int i,as=0,b=0;
    for(i=0;i<3;i++){
        if(a[i]=='A') as++;
        else b++;
    }
    if(as!=3&&b!=3) cout<<"Yes\n";
    else cout<<"No\n";
}
