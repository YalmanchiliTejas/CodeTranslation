#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(a[0]<=a[i])
        {
            c++;
            a[0]=a[i];
        }

    }
    cout<<c;
}


