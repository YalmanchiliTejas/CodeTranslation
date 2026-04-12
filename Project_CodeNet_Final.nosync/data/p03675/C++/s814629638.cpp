#include<bits/stdc++.h>
using namespace std;

int a[200005] , b[200005];

int main()
{

    int n;

    cin >> n;

    for(int i = 1 ; i<=n ; i++)
    {

        cin>> a[i];
    }

    int  l = 1;
    int r = n;
    int ll = n;
    int rr = n-1;

    while(l<=r)
    {
        b[r] = a[rr];
        b[l] = a[ll];
        l++;
        r--;
        ll-=2;
        rr-=2;
    }
    for(int i = 1 ; i<=n ; i++)
    {
        cout << b[i] << " ";
    }
}
