#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int count=1;
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>=max)
        {
            count++;
            max=a[i];
        }
    }
    cout<<count;
    return 0;
}