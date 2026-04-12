#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ans=0,maxx=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        if(maxx<=tmp)
        {
            ans++;
            maxx=tmp;
        }
    }
    cout<<ans<<'\n';
}