#include <iostream>

using namespace std;
int n;
int main()
{
    cin>>n;
    int v[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    int maxx=v[1],ans=0;
    for(int i=1;i<=n;i++)
    {
        if(maxx<=v[i])
        {
            ans++;
            maxx=v[i];
        }
    }
    cout<<ans;
    return 0;
}
