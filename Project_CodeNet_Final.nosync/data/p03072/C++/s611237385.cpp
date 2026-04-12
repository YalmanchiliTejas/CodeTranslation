#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i=i+1)
    {
        cin>>a[i];
    }
    int mn = 0, cnt = 0;
    for(i=0;i<n;i=i+1)
    {
        if(a[i] >= mn)
        {
            cnt = cnt + 1;
            mn = a[i];
        }
    }
    cout<<cnt;
}