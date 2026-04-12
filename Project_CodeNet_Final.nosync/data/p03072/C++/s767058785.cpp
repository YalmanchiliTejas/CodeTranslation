#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, flag, count = 0;
    cin>>n;

    int arr[n];

    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    flag = arr[0];

    for(i=0; i<n; i++)
    {
        if(flag <= arr[i])
            count++;
        if(flag < arr[i])
            flag = arr[i];

    }

    cout<<count;

}
