#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    multiset <int> is;
    for(int a,i=0; i<n; i++){
        scanf("%d",&a) ,a = 1e9-a;
        is.insert(a);
        auto it = is.upper_bound(a);
        if(it != is.end())
            is.erase(it);
    }
    printf("%d\n",is.size());
}
