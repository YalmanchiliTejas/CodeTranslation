#include <iostream>

using namespace std;
int n,a[22],res=0,maxa=0;
int main()
{
    //freopen("B.INP","r",stdin);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (maxa <= a[i]) res++;
        maxa=max(maxa,a[i]);
    }
    cout << res;
}
