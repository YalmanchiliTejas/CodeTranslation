#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+1 , M = 5e3+5;

int n , t , b[N] , sol;

int main()
{
    multiset<int> mu;
    multiset<int>::iterator it;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&t);
        it = mu.lower_bound(t);
        if(it==mu.begin())
            mu.insert(t);
        else
        {
            it--;
            mu.erase( it );
            mu.insert( t );
        }
    }
    printf("%d",mu.size());
    return 0;
}
