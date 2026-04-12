# include <bits/stdc++.h>
using namespace std;
list<int>l;
int main()
{
    int n, m, t=1;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&m);
        t = !t;
        if(t) l.push_back(m);
        else l.push_front(m);
    }
    if(!(n&1)) l.reverse();
    for(auto i=l.begin();i!=l.end();++i)
        printf("%d ",*i);
    return 0;
}
