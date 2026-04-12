#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define PI acos(-1.0)

typedef long long ll;
const int maxn=2e5+10;
int a[maxn],b[maxn];

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i],b[i]=a[i];
    sort(a+1,a+n+1);
    int mid=n/2;
    for(int i=1;i<=n;i++)
    {
        if(b[i]<=a[mid])
            cout << a[mid+1] << endl;
        else
            cout << a[mid] << endl;
    }
    return 0;
}

