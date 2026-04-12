/*
    Mbak Rose Dong
*/
#include<bits/stdc++.h>
using namespace std;
int arr[100100];
multiset<int> ms;
multiset<int>::iterator it;
int main()
{
    int n,i,j,k,x,y,ans,curr,temp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
        if(i == 1)
        {
            ms.insert(arr[i]);
        }
        else
        {
            it = ms.lower_bound(arr[i]);
            if(it == ms.begin())
            {
                ms.insert(arr[i]);
            }
            else
            {
                it--;
                ms.erase(it);
                ms.insert(arr[i]);
            }
        }
    }
    ans = (int)ms.size();
    printf("%d\n",ans);
    return 0;
}
