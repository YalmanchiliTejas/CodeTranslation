#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int n, ans = 1;
int a[MAXN], f[MAXN];
int main()
{
    scanf("%d", &n); for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    f[1] = a[1];
    for(int i = 2; i <= n; i++)
    {
        if(a[i] <= f[ans]) f[++ans] = a[i];
        else
        {
            int l = 1, r = ans;
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(f[mid] >= a[i]) l = mid + 1;
                else r = mid;
            }
            f[l] = a[i];
        }
    }
    printf("%d\n", ans);
//    system("pause");
}