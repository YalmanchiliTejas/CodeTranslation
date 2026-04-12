#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n;
    int d;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> d;
        a[i]=d/10;
    }
    int mx=0;
    bool flag=true;
    for(int i=0;i<n;i++){
        mx=max(mx,a[i]+i);
        if(mx<=i)flag=false;
    }
    reverse(a,a+n);
    mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,a[i]+i);
        if(mx<=i)flag=false;
    }
    if(flag)puts("yes");
    else puts("no");
    return 0;
}

