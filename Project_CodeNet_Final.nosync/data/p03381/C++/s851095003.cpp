#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n,mm[200005],mmnn[200005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>mm[i];
        mmnn[i]=mm[i];
    }
    sort(mm,mm+n);
    int ans=mm[n/2];
    for(int i=0;i<n;i++)
    {
        if(ans>mmnn[i])cout<<mm[n/2]<<endl;
        else cout<<mm[n/2-1]<<endl;
    }
    return 0;
}