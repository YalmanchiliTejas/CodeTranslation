#include<bits/stdc++.h>
using namespace std;
multiset<int>s;
multiset<int>::iterator it;
int x[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int a=1;a<=n;a++)
    {
        scanf("%d",&x[a]);
        s.insert(x[a]);
    }
        int d=n+1;
        d/=2;
        it=s.begin();
        for(int a=1;a<d;a++)
            it++;
        for(int a=1;a<=n;a++)
        {
            if(x[a]<=*it)
            {
                it++;
                printf("%d\n",*it);
                it--;
            }
            else
                printf("%d\n",*it);
        }

}

