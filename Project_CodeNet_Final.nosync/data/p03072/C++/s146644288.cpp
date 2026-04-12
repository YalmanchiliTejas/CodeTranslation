#include<bits/stdc++.h>
using namespace std;
int n,o,x;
int main()
{
    cin>>n>>o;
    int ans=1;
    for(int i=2;i<=n;i++){
        cin>>x;
        if(x>=o)ans++,o=x;
    }
    cout<<ans<<endl;
    return 0;
}