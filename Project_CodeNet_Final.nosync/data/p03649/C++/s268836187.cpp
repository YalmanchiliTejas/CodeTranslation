#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define PI acos(-1.0)

typedef long long ll;
const int maxn=100;
ll a[100],n,k;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    while(1)
    {
        ll maxx=-1,index=0;
        for(int i=0;i<n;i++)
            if(maxx<a[i])
                maxx=a[i],index=i;
        if(maxx<n)
            break;
        for(int i=0;i<n;i++)
        {
            if(index==i)
                a[i]%=n;
            else
                a[i]+=(maxx/n);
        }
        k+=(maxx/n);
    }
    cout << k << endl;
    return 0;
}
