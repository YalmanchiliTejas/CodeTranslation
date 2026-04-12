#include <iostream>
#include <algorithm>
using namespace std;
int i,g[10000000],a[10000000],len;
const int inf=0x7f7f7f7f;
int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    reverse(a + 1, a + n + 1);
    g[0]=-inf;
    for (int i = 1; i <= n; i++)
    {
        if(a[i]>=g[len])
        {
            len++;
            g[len]=a[i];
            continue;
        }
        int x=0,y=len,mid;
        while(x<y)
        {
            mid=(x+y)>>1;
            if(g[mid]>a[i])
                y=mid;
            else
                x=mid+1;
        }//二分在g数组里找第一个大于等于a[i]的数
        g[x]=min(g[x],a[i]);//进行比较，贪心思想
    }
    cout<<len<<endl;
    return 0;
}

