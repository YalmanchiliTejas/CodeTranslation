#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5,mod = 10399;

int n,p1,p2,p,a[maxn],b[maxn],l,p3,p4;

long long ans;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        l = i / 2;
        b[l] = a[n - (l*2) - 1];
        if(n - (l*2) - 2 < 0)
            break;
        b[n - l - 1] = a[n - (l*2) - 2];
        l++;
    }
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
}
