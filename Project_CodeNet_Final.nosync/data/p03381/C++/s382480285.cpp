#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> que,ans;

int main()
{
    int n,pp;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pp);
        que.push_back(pp);
        ans.push_back(pp);
    }
    sort(ans.begin(),ans.end());
    int med = ans[n/2];
    for(int i=0;i<n;i++)
    {
        if(que[i]<med)
            printf("%d\n",med);
        else
            printf("%d\n",ans[n/2-1]);
    }
}
