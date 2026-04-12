#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int n,a[MAXN],ans[MAXN];
struct discretization_node
{
    int num;
    int ki;
} disc[MAXN];
bool cmp(discretization_node x,discretization_node y)
{
    return x.num<y.num;
}
void discretization(int a[],int n,discretization_node disc[])
{
    for(int i=0; i<n; ++i)
    {
        disc[i].num=a[i];
        disc[i].ki=i;
    }
    sort(disc,disc+n,cmp);
    int cnt=0,pre;
    for(int i=0; i<n; ++i)
    {
        if(i==0||a[disc[i].ki]!=pre)++cnt;
        pre=a[disc[i].ki];
        a[disc[i].ki]=cnt;
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&a[i]);
    }
    discretization(a,n,disc);
    reverse(a,a+n);
    int pans = 1, j;
    ans[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] >= ans[pans - 1])
            ans[pans ++] = a[i];
        else
        {
            j = upper_bound(ans, ans + pans, a[i]) - ans;
            ans[j] = a[i];
        }
    }
    printf("%d\n", pans);
    return 0;
}
