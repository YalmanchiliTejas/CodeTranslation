// its_mind_changer_
//                         _don't_under_estimate_
#include<bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
    string a;cin>>a;
    int x=0;
    for(int i=0;i<3;i++) if(a[i]=='A') x++;
    if(x and x!=3) cout<<"Yes\n";
    else cout<<"No\n";
}
