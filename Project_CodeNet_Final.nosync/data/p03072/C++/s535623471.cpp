#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    int maxa=0;
    int count=0;

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    for (int i = 0; i < n; ++i) {
        if(a[i]>=maxa)
        {
            maxa=a[i];
            count++;
        }
    }
    cout<<count;
}