#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    int maxa[n+1];
    maxa[0]=0;
    int count=0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        maxa[i+1]=max(maxa[i],a[i]);
        if(maxa[i+1]<=a[i])
            count++;
    }
    cout<<count;
}