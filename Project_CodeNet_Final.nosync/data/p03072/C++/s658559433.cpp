#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[50];
    int n;
    cin >> n;
    int i,j,ci=0,u;
    for(i=0;i<n;i++)
        cin >> a[i];
    for(i=n-1;i>=0;i--)
    {
        u=0;
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>a[i])
                u=1;
        }
        if(u==0)
            ci++;
    }
    cout << ci << endl;
    return 0;
}