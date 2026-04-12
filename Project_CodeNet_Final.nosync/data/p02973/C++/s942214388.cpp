#include<bits/stdc++.h>
using namespace std;
int a[100005];
multiset<int> st;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        multiset<int>::iterator cur=st.lower_bound(a[i]);//查找最大的比该元素小的元素 lower-1
        if(cur==st.begin())
        {
            st.insert(a[i]);
        }
        else
        {
            cur--;
            st.erase(cur);
            st.insert(a[i]);
        }
    }
    printf("%d\n",st.size());
}
