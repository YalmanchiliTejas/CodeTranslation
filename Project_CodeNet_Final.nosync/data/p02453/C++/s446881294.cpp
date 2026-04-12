#include <bits/stdc++.h>
using namespace std;
int n, q, v,l,r;
int lowerBound(int a[], int x)
{
    int l = 0, r = n - 1;
    int res = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] >= x)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}

int main()
{
    cin >> n;
    int a[n];
    for( int i = 0; i < n; i++ ){
        cin >> a[i];   
    }
    cin >> q;
    for( int i = 0; i < q; i++ )
    {
        cin >> v;
        cout << lowerBound( a, v) << "\n";
    }
    return 0;
}
