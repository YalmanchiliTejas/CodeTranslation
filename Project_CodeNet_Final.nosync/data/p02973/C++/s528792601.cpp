#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int n,x;
multiset<int>a;
multiset<int>::iterator it;

int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&x);
        if(a.empty())
            a.insert(x);
        else
        {
            it = a.lower_bound(x);
            if(it==a.begin())
                a.insert(x);
            else
            {
                it--;
                a.erase(it);
                a.insert(x);
            }
        }
    }
    int ans = a.size();
    printf("%d\n",ans);
    return 0;
}
