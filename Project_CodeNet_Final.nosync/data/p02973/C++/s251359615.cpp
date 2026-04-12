#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
multiset<int>s;
int main()
{

    int ans=0;
    int n;scanf("%d",&n);
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        x=-x;
        multiset<int>::iterator it=s.upper_bound(x);
        if(it==s.end())
        {
            ans++;
        }
        else
        {
            s.erase(it);
        }
        s.insert(x);
    }
    cout<<ans<<endl;
    return 0;
}
