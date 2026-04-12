#include<cstdio>
#include<set>
using namespace std;
const int MAXN=100005;
int n,a[MAXN],ans;
multiset<int>low;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i) scanf("%d",&a[i]);
    for (int i=1;i<=n;++i)
    {
        set<int>::iterator sec=low.upper_bound(-a[i]);
        if(sec!=low.end())
        {
            low.erase(sec);
            low.insert(-a[i]);
        } else {
            low.insert(-a[i]);
            ++ans;
        }
    }
    printf("%d",ans);
    return 0;
}