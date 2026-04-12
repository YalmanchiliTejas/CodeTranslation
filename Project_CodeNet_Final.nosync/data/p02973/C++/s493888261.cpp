#include <bits/stdc++.h>
#define INF 0x7f7f7f7f

using namespace std;

int n;
int a;
multiset<int>s;

int main()
{
    scanf("%d",&n);
    s.insert(-1);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a);
        multiset<int>::iterator it = s.lower_bound(a);
        if(it != s.begin())
            s.erase(--it);
        s.insert(a);
    }
    printf("%d\n",s.size());
    return 0;
}
