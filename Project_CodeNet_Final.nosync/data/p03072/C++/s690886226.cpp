#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int ile=1;
    int n; cin>>n;
    int * a=new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int maxx=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>=maxx) ile++;
        maxx=max(maxx,a[i]);
    }
    cout<<ile;
    return 0;
}