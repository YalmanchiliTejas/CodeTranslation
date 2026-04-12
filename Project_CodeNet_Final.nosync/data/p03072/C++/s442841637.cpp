#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,c=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    //sort(a,a+n);
    //for(i=0;i<n;i++)
    //cout<<a[i]<<" ";
    int maxx=0;
    for(i=0;i<n;i++)
    {
        if(a[i]>=maxx)
        {
            c++;
            maxx=a[i];
        }
    }
    cout<<c;
}
