#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++)cin>>arr[i];
    int counter=0,sum=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=sum)counter++;
        sum=max(arr[i],sum);
    }
    cout<<counter<<endl;
}
