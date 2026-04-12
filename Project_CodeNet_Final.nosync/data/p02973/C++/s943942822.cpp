#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
using namespace std;
const int M=1e5+10;
int n,ans,a[M];
multiset<int> last;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        auto item=last.lower_bound(a[i]);
        if(item==last.begin())
            ans++,last.insert(a[i]);
        else
        {
            item--;
            last.erase(item);
            last.insert(a[i]);
        }
    }
    printf("%d\n",ans);
    return 0;
}

