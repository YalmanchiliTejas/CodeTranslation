#include <iostream>

using namespace std;
int n;
int v[22];
int main()
{
    cin>>n;
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
    cout<<ans<<"\n";
    return 0;
}
